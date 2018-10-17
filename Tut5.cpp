#include <climits>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

TreeNode *recursiveInsert(TreeNode *subroot, TreeNode *newNode)
{
    if (subroot == nullptr) {
        subroot = newNode;
        return newNode;
    }
    if (subroot->data > newNode->data)
        return recursiveInsert(subroot->left, newNode);
    if (subroot->data < newNode->data)
        return recursiveInsert(subroot->right, newNode);
    return subroot;
}

void printPath(TreeNode *subroot, int searchedData)
{
    bool flag = false;
    string path = "";
    TreeNode *temp = subroot;
    while (temp != nullptr) {
        path += to_string(temp->data);
        if (temp->data > searchedData) {
            temp = temp->right;
        } else if (temp->data < searchedData) {
            temp = temp->left;
        } else {
            flag = true;
            break;
        }
        path += "->";
    }
    cout << path;
}

void printLeavesBFT(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> qTreeNode;
    qTreeNode.push(root);
    while (!qTreeNode.empty()) {
        TreeNode *temp = qTreeNode.front();
        qTreeNode.pop();
        int count = 0;
        if (temp->left != nullptr) {
            qTreeNode.push(temp->left);
            ++count;
        }
        if (temp->right != nullptr) {
            qTreeNode.push(temp->right);
            ++count;
        }
        if (count == 0)
            cout << temp->data << "\t";
    }
}

void printLeavesLNR(TreeNode *subroot)
{
    if (subroot == nullptr)
        return;
    printLeavesLNR(subroot->left);
    if (subroot->left == nullptr && subroot->right == nullptr) {
        cout << subroot->data << "\t";
        return;
    }
    printLeavesLNR(subroot->right);
}

void printLeavesNLR(TreeNode *subroot)
{
    if (subroot == nullptr)
        return;
    if (subroot->left == nullptr && subroot->right == nullptr) {
        cout << subroot->data << "\t";
        return;
    }
    printLeavesNLR(subroot->left);
    printLeavesNLR(subroot->right);
}

bool checkBST_recur(TreeNode *subroot, int &min, int &max)
{
    if (subroot == nullptr) {
        return true;
    }
    bool b = true;
    int minL = INT_MAX;
    int maxL = INT_MIN;
    int minR = INT_MAX;
    int maxR = INT_MIN;
    if (subroot->left != nullptr) {
        b = (b && checkBST_recur(subroot->left, minL, maxL));
    }
    if (subroot->right != nullptr) {
        b = (b && checkBST_recur(subroot->right, minR, maxR));
    }
    if (minL < subroot->data) {
        min = minL;
    } else {
        min = subroot->data;
        b = false;
    }
    if (maxR > subroot->data) {
        max = maxR;
    } else {
        max = subroot->data;
        b = false;
    }
    if (minR < subroot->data) {
        b = false;
        if (minR < min)
            min = minR;
    }
    if (maxL > subroot->data) {
        b = false;
        if (maxL > max)
            max = maxL;
    }
    return b;
}

int main()
{
    return 0;
}
