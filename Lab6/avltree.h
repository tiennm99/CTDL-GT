#ifndef AVLTREE_H
#define AVLTREE_H

#include <stack>
#include "avlnode.h"

template <class T>
class AVLTree
{
private:
    AVLNode<T> *root = nullptr;
    AVLNode<T> *rotateLeft(AVLNode<T> *node);
    AVLNode<T> *rotateRight(AVLNode<T> *node);
    int getHeight(AVLNode<T> *node);
    void rebalance(AVLNode<T> *node);
public:
    AVLTree();
    ~AVLTree();
    bool insert(AVLNode<T> *newNode);
    AVLNode<T> *search(T searchData);
    bool remove(const T removeData);
    void printAsList();
    void printNLR();
    template <class U>
    friend ostream &operator << (ostream &os, AVLTree<U> *tree);
};

template <class T>
AVLTree<T>::AVLTree()
{
    this->root = nullptr;
}

template <class T>
AVLTree<T>::~AVLTree()
{
    delete this->root;
    this->root = nullptr;
}

template <class T>
void AVLTree<T>::rebalance(AVLNode<T> *node)
{
    if (node == nullptr)
        return;
    node->update();
    if (node->balance > 1) {
        if (node->left->balance < -1)
            node->left = rotateLeft(node->left);
        node = rotateRight(node);
    } else if (node->balance < -1) {
        if (node->right->balance > 1)
            node->right = rotateRight(node->right);
        node = rotateLeft(node);
    }
    if (node->parent == nullptr)
        this->root = node;
    else
        rebalance(node->parent);
}

template <class T>
AVLNode<T> *AVLTree<T>::rotateLeft(AVLNode<T> *node)
{
    AVLNode<T> *temp = node->right;
    AVLNode<T> *tmp = temp->left;
    AVLNode<T> *parent = node->parent;
    temp->parent = parent;
    node->right = tmp;
    if (tmp != nullptr) {
        tmp->parent = node;
    }
    temp->left = node;
    node->parent = temp;
    if (parent != nullptr) {
        if (parent->left == node)
            parent->left = temp;
        else
            parent->right = temp;
    }
    node->update();
    temp->update();
    return temp;
}

template <class T>
AVLNode<T> *AVLTree<T>::rotateRight(AVLNode<T> *node)
{
    AVLNode<T> *temp = node->left;
    AVLNode<T> *tmp = temp->right;
    AVLNode<T> *parent = node->parent;
    temp->parent = parent;
    node->left = tmp;
    if (tmp != nullptr) {
        tmp->parent = node;
    }
    temp->right = node;
    node->parent = temp;
    if (parent != nullptr) {
        if (parent->left == node)
            parent->left = temp;
        else
            parent->right = temp;
    }
    node->update();
    temp->update();
    return temp;
}

template <class T>
int AVLTree<T>::getHeight(AVLNode<T> *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

template <class T>
bool AVLTree<T>::insert(AVLNode<T> *newNode)
{
    if (newNode == nullptr)
        return false;
    if (this->root == nullptr) {
        this->root = newNode;
        return true;
    }
    AVLNode<T> *temp = this->root;
    AVLNode<T> *parent;
    while (true) {
        if (temp->data == newNode->data)
            return false;
        parent = temp;
        bool goLeft = (newNode->data < temp->data);
        temp = goLeft ? temp->left : temp->right;
        if (temp == nullptr) {
            if (goLeft) {
                parent->left = newNode;
                newNode->parent = parent;
            } else {
                parent->right = newNode;
                newNode->parent = parent;
            }
            rebalance(parent);
            return true;
        }
    }
}

template <class T>
bool AVLTree<T>::remove(const T removeData)
{
    AVLNode<T> *temp = this->root;
    while (temp != nullptr) {
        if (removeData < temp->data)
            temp = temp->left;
        else if (removeData > temp->data)
            temp = temp->right;
        else
            break;
    }
    if (temp == nullptr)
        return false;
    AVLNode<T> *del = temp;
    if (temp->left != nullptr) {
        del = temp->left;
        while (del->right != nullptr)
            del = del->right;
    }
    AVLNode<T> *parent = nullptr;
    if (del == this->root) {
        this->root = this->root->right;
        if (this->root != nullptr)
            this->root->parent = nullptr;
    } else if (del != temp) {
        temp->data = del->data;
        parent = del->parent;
        if (parent->left == del)
            parent->left = del->left;
        else
            parent->right = del->left;
        if (del->left != nullptr)
            del->left->parent = parent;
    } else {
        parent = del->parent;
        if (parent->left == del)
            parent->left = del->right;
        else
            parent->right = del->right;
        if (del->right != nullptr)
            del->right->parent = parent;
    }
    if (parent != nullptr)
        this->rebalance(parent);
    return true;
}

template <class T>
void AVLTree<T>::printNLR()
{
    stack<AVLNode<T> *> sAVLNode;
    stack<int> sNodeLevel;
    sAVLNode.push(this->root);
    sNodeLevel.push(0);
    while (!sAVLNode.empty()) {
        AVLNode<T> *tNode = sAVLNode.top();
        sAVLNode.pop();
        int tLevel = sNodeLevel.top();
        sNodeLevel.pop();
        for (int i = 0; i < tLevel; ++i) {
            cout << "    ";
        }
        if (tNode == nullptr) {
            cout << "NULL" << endl;
            continue;
        }
        cout << tNode->data << "(" << tNode->balance << ")" << endl;
        sAVLNode.push(tNode->right);
        sNodeLevel.push(tLevel + 1);
        sAVLNode.push(tNode->left);
        sNodeLevel.push(tLevel + 1);
    }
}

template <class T>
AVLNode<T> *AVLTree<T>::search(T searchData)
{
    AVLNode<T> *temp = this->root;
    while (temp != nullptr) {
        if (searchData < temp->data)
            temp = temp->left;
        else if (searchData > temp->data)
            temp = temp->right;
        else
            return temp;
    }
    return nullptr;
}

template <class T>
void printLNR(AVLNode<T> *subroot)
{
    if (subroot == nullptr)
        return;
    printLNR(subroot->left);
    cout << subroot->data << endl;
    printLNR(subroot->right);
}

template <class T>
void AVLTree<T>::printAsList()
{
    printLNR(this->root);
}

template <class T>
ostream &operator << (ostream &os, AVLTree<T> *tree)
{
    os << tree->root;
    return os;
}

#endif // AVLTREE_H
