#ifndef AVLNODE_H
#define AVLNODE_H

#include <iostream>

using namespace std;

template <class T>
class AVLNode
{
public:
    T data;
    int balance = 0;
    int height = 1;
    AVLNode *parent = nullptr;
    AVLNode *left = nullptr;
    AVLNode *right = nullptr;
    AVLNode();
    AVLNode(T data);
    ~AVLNode();
    void update();
    void print(int space);
    template <class U>
    friend ostream &operator << (ostream &os, AVLNode<U> *node);
};

template <class T>
AVLNode<T>::AVLNode()
{
    this->balance = 0;
    this->height = 1;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
AVLNode<T>::AVLNode(T data)
{
    this->data = data;
    this->balance = 0;
    this->height = 1;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
AVLNode<T>::~AVLNode()
{
    this->parent = nullptr;
    delete this->left;
    this->left = nullptr;
    delete this->right;
    this->right = nullptr;
}

template <class T>
void AVLNode<T>::update()
{
    int hl = 0;
    int hr = 0;
    if (this->left != nullptr)
        hl = this->left->height;
    if (this->right != nullptr)
        hr = this->right->height;
    this->height = max(hl, hr) + 1;
    this->balance = hl - hr;
}

template <class T>
void AVLNode<T>::print(int space)
{
    if (space < 0)
        return;
    for (int i = 0; i < space - this->height; ++i)
        cout << "\t";
    this->print();
}

template <class T>
ostream &operator << (ostream &os, AVLNode<T> *node)
{
    if (node == nullptr)
        return os;
    os << node->left;
    os << node->data;
    os << node->right;
    return os;
}

#endif // AVLNODE_H
