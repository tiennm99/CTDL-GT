#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "treenode.h"

class BinarySearchTree
{
public:
    TreeNode *root = nullptr;
    void insert(TreeNode *node);
    void remove(int removeData);
    void print();
};

#endif // BINARYSEARCHTREE_H
