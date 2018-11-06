#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;

class TreeNode
{
private:
    int data;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
public:
    TreeNode(int data);
    ~TreeNode();
    int getData();
    void setData(int newdata);
    TreeNode *getLeft();
    void setLeft(TreeNode *newLeft);
    TreeNode *getRight();
    void setRight(TreeNode *newRight);
    void print();
};

#endif // TREENODE_H
