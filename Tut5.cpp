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

TreeNode *recursiveInsert(TreeNode *&subroot, TreeNode *newNode)
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
        if (temp->data < searchedData) {
            temp = temp->right;
        } else if (temp->data > searchedData) {
            temp = temp->left;
        } else {
            flag = true;
            break;
        }
        path += "->";
    }
    if (flag == true)
        cout << path << endl;
    else
        cout << "Khong tim thay phan tu " << searchedData << " trong cay!" << endl;
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
        min = INT_MAX;
        max = INT_MIN;
        return true;
    }
    int minL, maxL, minR, maxR;
    bool b1 = checkBST_recur(subroot->left, minL, maxL);
    bool b2 = checkBST_recur(subroot->right, minR, maxR);
    if (maxR >= maxL && maxR >= subroot->data)
        max = maxR;
    else if (maxL >= maxR && maxL >= subroot->data)
        max = maxL;
    else
        max = subroot->data;
    if (minL <= minR && minL <= subroot->data)
        min = minL;
    else if (minR <= minL && minR <= subroot->data)
        min = minR;
    else
        min = subroot->data;
    return b1 && b2 && (subroot->data > maxL) && (subroot->data < minR);
}

int main()
{
    int arr[] = {15, 7, 1, 11, 9, 13, 20};
    TreeNode *tree = nullptr;
    for (int i = 0; i < 7; ++i) {
        TreeNode *temp = new TreeNode;
        temp->data = arr[i];
        recursiveInsert(tree, temp);
    }
    for (int i = 0; i < 7; ++i) {
        printPath(tree, arr[i]);
    }
    printPath(tree, 8);
    printLeavesBFT(tree);
    cout << endl;
    printLeavesLNR(tree);
    cout << endl;
    printLeavesNLR(tree);
    cout << endl;
    int min, max;
    bool b = checkBST_recur(tree, min, max);
    if (b)
        cout << "Day la cay nhi phan tim kiem" << endl;
    else
        cout << "Day khong phai cay nhi phan tim kiem" << endl;
    cout << "min = " << min << endl;
    cout << "max = " << max << endl;
    return 0;
}
