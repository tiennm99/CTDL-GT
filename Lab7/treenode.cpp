#include "treenode.h"

TreeNode::TreeNode(int data)
{
    this->data = data;
}

TreeNode::~TreeNode()
{
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
}


int TreeNode::getData()
{
    return this->data;
}

void TreeNode::setData(int newData)
{
    this->data = newData;
}

TreeNode *TreeNode::getLeft()
{
    return this->left;
}

void TreeNode::setLeft(TreeNode *newLeft)
{
    this->left = newLeft;
}

TreeNode *TreeNode::getRight()
{
    return this->right;
}

void TreeNode::setRight(TreeNode *newRight)
{
    this->right = newRight;
}

void TreeNode::print()
{
    cout << "(";
    if (this->left != nullptr)
        this->left->print();
    cout << this->data;
    if (this->right != nullptr)
        this->right->print();
    cout << ")";
}
