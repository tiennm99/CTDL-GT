#include "binarysearchtree.h"

void BinarySearchTree::insert(TreeNode *node)
{
    if (this->root == nullptr) {
        this->root = node;
        return;
    }
    TreeNode *temp = this->root;
    while (true) {
        if (temp->getData() > node->getData()) {
            if (temp->getLeft() == nullptr) {
                temp->setLeft(node);
                return;
            }
            temp = temp->getLeft();
        } else if (temp->getData() < node->getData()) {
            if (temp->getRight() == nullptr) {
                temp->setRight(node);
                return;
            }
            temp = temp->getRight();
        } else {
            return;
        }
    }
}

void BinarySearchTree::remove(int removeData)
{
    if (this->root == nullptr)
        return;
    TreeNode *preTemp = nullptr;
    TreeNode *temp = this->root;
    while (temp != nullptr) {
        if (temp->getData() > removeData) {
            preTemp = temp;
            temp = temp->getLeft();
        } else if (temp->getData() < removeData) {
            preTemp = temp;
            temp = temp->getRight();
        } else {
            break;
        }
    }
    if (temp != nullptr) {
        if (temp->getLeft() != nullptr) {
            TreeNode *preMaxL = nullptr;
            TreeNode *maxL = temp->getLeft();
            while (maxL->getRight() != nullptr) {
                preMaxL = maxL;
                maxL = maxL->getRight();
            }
            temp->setData(maxL->getData());
            if (preMaxL != nullptr)
                preMaxL->setRight(maxL->getLeft());
            else
                temp->setLeft(maxL->getLeft());
            delete maxL;
        } else {
            if (preTemp != nullptr) {
                if (preTemp->getLeft() == temp)
                    preTemp->setLeft(temp->getRight());
                else
                    preTemp->setRight(temp->getRight());
            } else {
                this->root = temp->getRight();
            }
            delete temp;
        }
    }
}

void BinarySearchTree::print()
{
    if (this->root == nullptr)
        return;
    this->root->print();
    cout << endl;
}
