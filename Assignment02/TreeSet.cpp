//use "balance" varialbe as "height"

#include "TreeSet.h"

static bool isSuccess;

TreeSet::TreeSet()
{
    root = nullptr;
    count = 0;
}

TreeSet::~TreeSet()
{
    clear();
}

void TreeSet::clearRec(AVLNode *root)
{
    if (root != nullptr) {
        clearRec(root->left);
        clearRec(root->right);
        delete root;
    }
}

void TreeSet::clear()
{
    clearRec(root);
    root = nullptr;
    count = 0;
}

int TreeSet::add(int val)
{
    isSuccess = false;
    root = recursiveAdd(root, val);
    if (isSuccess) {
        ++count;
        return true;
    }
    return false;
}

bool TreeSet::contains(int val)
{
    AVLNode *temp = root;
    while (temp != nullptr) {
        if (temp->key > val)
            temp = temp->left;
        else if (temp->key < val)
            temp = temp->right;
        else
            return true;
    }
    return false;
}

void TreeSet::copy(const TreeSet &set)
{
    clear();
    root = recursiveCopy(set.root);
    count = set.count;
}

int TreeSet::first()
{
    if (root == nullptr) {
        throw "NoSuchElementException";
    }
    AVLNode *temp = root;
    while (temp->left != nullptr)
        temp = temp->left;
    return temp->key;
}

int TreeSet::last()
{
    if (root == nullptr) {
        throw "NoSuchElementException";
    }
    AVLNode *temp = root;
    while (temp->right != nullptr)
        temp = temp->right;
    return temp->key;
}

int TreeSet::higher(int val)
{
    if (root == nullptr)
        return -1;
    int higher = last();
    if (val >= higher)
        return -1;
    AVLNode *temp = root;
    while (temp != nullptr) {
        if (temp->key > val) {
            if (temp->key < higher)
                higher = temp->key;
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return higher;
}

int TreeSet::lower(int val)
{
    if (root == nullptr)
        return -1;
    int lower = first();
    if (val <= lower)
        return -1;
    AVLNode *temp = root;
    while (temp != nullptr) {
        if (temp->key < val) {
            if (temp->key > lower)
                lower = temp->key;
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return lower;
}

int TreeSet::remove(int val)
{
    isSuccess = false;
    root = recursiveRemove(root, val);
    if (isSuccess) {
        --count;
        return true;
    }
    return false;
}


TreeSet *TreeSet::subSet(int fromVal, int toVal)
{
    TreeSet *subSet = new TreeSet;
    recursiveSubSet(subSet, root, fromVal, toVal);
    return subSet;
}

int TreeSet::size()
{
    return count;
}

int TreeSet::getHeight(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    return node->balance;
}

void TreeSet::setHeight(AVLNode *&node)
{
    node->balance = max(getHeight(node->left), getHeight(node->right)) + 1;
}

int TreeSet::getBalance(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void TreeSet::recursiveSubSet(TreeSet *&subSet, AVLNode *node, int fromVal, int toVal)
{
    if (node == nullptr)
        return;
    if (node->key < fromVal) {
        recursiveSubSet(subSet, node->right, fromVal, toVal);
    } else if (node->key < toVal) {
        subSet->add(node->key);
        recursiveSubSet(subSet, node->left, fromVal, toVal);
        recursiveSubSet(subSet, node->right, fromVal, toVal);
    } else {
        recursiveSubSet(subSet, node->left, fromVal, toVal);
    }
}

AVLNode *TreeSet::recursiveAdd(AVLNode *&node, int val)
{
    if (node == nullptr) {
        isSuccess = true;
        return new AVLNode(val, 1);
    }
    if (node->key == val)
        return node;
    if (node->key > val)
        node->left = recursiveAdd(node->left, val);
    else
        node->right = recursiveAdd(node->right, val);
    setHeight(node);
    return rebalance(node);
}

AVLNode *TreeSet::recursiveRemove(AVLNode *&node, int val)
{
    if (node == nullptr)
        return node;
    if (node->key > val) {
        node->left = recursiveRemove(node->left, val);
    } else if (node->key < val) {
        node->right = recursiveRemove(node->right, val);
    } else {
        if (node->left == nullptr) {
            AVLNode *temp = node->right;
            delete node;
            isSuccess = true;
            return temp;
        }
        AVLNode *delNode = node->left;
        while (delNode->right != nullptr)
            delNode = delNode->right;
        node->key = delNode->key;
        node->left = recursiveRemove(node->left, node->key);
    }
    return rebalance(node);
}

AVLNode *TreeSet::recursiveCopy(AVLNode *node)
{
    if (node == nullptr)
        return node;
    AVLNode *temp = new AVLNode(node->key, node->balance);
    temp->left = recursiveCopy(node->left);
    temp->right = recursiveCopy(node->right);
    return temp;
}

AVLNode *TreeSet::rotateLeft(AVLNode *&node)
{
    AVLNode *temp = node->right;
    AVLNode *tmp = temp->left;
    node->right = tmp;
    temp->left = node;
    setHeight(node);
    setHeight(temp);
    return temp;
}

AVLNode *TreeSet::rotateRight(AVLNode *&node)
{
    AVLNode *temp = node->left;
    AVLNode *tmp = temp->right;
    node->left = tmp;
    temp->right = node;
    setHeight(node);
    setHeight(temp);
    return temp;
}

AVLNode *TreeSet::rebalance(AVLNode *&node)
{
    if (node == nullptr)
        return nullptr;
    int balance = getBalance(node);
    if (balance > 1) {
        if (getBalance(node->left) < -1)
            node->left = rotateLeft(node->left);
        node = rotateRight(node);
    } else if (balance < -1) {
        if (getBalance(node->right) > 1)
            node->right = rotateRight(node->right);
        node = rotateLeft(node);
    }
    return node;
}
