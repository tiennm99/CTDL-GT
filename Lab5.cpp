#include <iostream>
#include <stack>

using namespace std;

class TreeNode
{
private:
    string character;
    int count;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
public:
    TreeNode(string character);         // TODO
    TreeNode(char character);           // TODO
    ~TreeNode();                        // TODO
    void increaseCount();               // TODO: increase "count" by 1
    // get/set methods
    int getCount();                     // TODO
    void setCount(int newCount);        // TODO
    string getChar();                   // TODO
    void setChar(string newChar);       // TODO
    TreeNode *getLeft();                // TODO
    void setLeft(TreeNode *newLeft);    // TODO
    TreeNode *getRight();               // TODO
    void setRight(TreeNode *newRight);  // TODO
};

class BinarySearchTree
{
public:
    TreeNode *root = nullptr;
    void insert(TreeNode *node);
    // TODO: insert a node, if the "character" of "node" does exist, then increase the "count"
    void remove(string character);
    // TODO: remove/delete a node having the same "character"
    int search(string character);
    // TODO: return "count"
    void print();
    // TODO: print out the whole tree on the console
};

TreeNode::TreeNode(string character)
{
    this->character = character;
}

TreeNode::TreeNode(char character)
{
    string s(1, character);
    this->character = s;
}

TreeNode::~TreeNode()
{
    this->character = "";
    this->count = 0;
    this->left = nullptr;
    this->right = nullptr;
}

void TreeNode::increaseCount()
{
    ++this->count;
}

int TreeNode::getCount()
{
    return this->count;
}

void TreeNode::setCount(int newCount)
{
    if (newCount > 0) {
        this->count = newCount;
    }
}

string TreeNode::getChar()
{
    return this->character;
}

void TreeNode::setChar(string newChar)
{
    if (newChar.length() == 1) {
        this->character = newChar;
    }
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

void BinarySearchTree::insert(TreeNode *node)
{
    if (this->root == nullptr) {
        this->root = node;
        return;
    }
    TreeNode *temp = this->root;
    while (true) {
        if (temp->getChar() > node->getChar()) {
            if (temp->getLeft() == nullptr) {
                temp->setLeft(node);
                return;
            }
            temp = temp->getLeft();
        } else if (temp->getChar() < node->getChar()) {
            if (temp->getRight() == nullptr) {
                temp->setRight(node);
                return;
            }
            temp = temp->getRight();
        } else {
            temp->increaseCount();
            return;
        }
    }
}

void BinarySearchTree::remove(string character)
{
    if (this->root == nullptr)
        return;
    TreeNode *preTemp = nullptr;
    TreeNode *temp = this->root;
    while (temp != nullptr) {
        if (temp->getChar() > character) {
            preTemp = temp;
            temp = temp->getLeft();
        } else if (temp->getChar() < character) {
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
            temp->setChar(maxL->getChar());
            temp->setCount(maxL->getCount());
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

int BinarySearchTree::search(string character)
{
    TreeNode *temp = this->root;
    while (temp != nullptr) {
        if (temp->getChar() > character)
            temp = temp->getLeft();
        else if (temp->getChar() < character)
            temp = temp->getRight();
        else
            return temp->getCount();
    }
    return 0;
}

void BinarySearchTree::print()
{
    if (this->root == nullptr)
        return;
    stack<TreeNode *> sTreeNode;
    stack<int> sNodeLevel;
    sTreeNode.push(this->root);
    sNodeLevel.push(0);
    while (!sTreeNode.empty()) {
        TreeNode *tNode = sTreeNode.top();
        sTreeNode.pop();
        int tLevel = sNodeLevel.top();
        sNodeLevel.pop();
        for (int i = 0; i < tLevel; ++i) {
            cout << "    ";
        }
        if (tNode == nullptr) {
            cout << "NULL" << endl;
            continue;
        }
        cout << tNode->getChar() << "(" << tNode->getCount() << ")" << endl;
        sTreeNode.push(tNode->getRight());
        sNodeLevel.push(tLevel + 1);
        sTreeNode.push(tNode->getLeft());
        sNodeLevel.push(tLevel + 1);
    }
}

BinarySearchTree *buildTreeFromString(string str)
{
    BinarySearchTree *bst = new BinarySearchTree;
    for (unsigned int i = 0; i < str.length(); ++i) {
        TreeNode *temp = new TreeNode(str[i]);
        temp->setCount(1);
        bst->insert(temp);
    }
    return bst;
}

int main()
{
    string n = "skvhsedjfokeporpiweptreotoretiorjituwesdjfksdjlkfjlkekkejlkwj";
    string d = "qwertyuiopasdfghjklzxcvbnm";
    BinarySearchTree *bst = buildTreeFromString(n);
    bst->print();
    for (unsigned int i = 0; i < d.length(); ++i) {
        string s(1, d[i]);
        cout << "Remove string " + s + " from tree:" << endl;
        bst->remove(s);
        bst->print();
    }
    return 0;
    /*
    string str = "A binary search tree is a binary tree with the following\
    properties: All items in the left subtree are less than the root. All items in the\
    right subtree are greater than or equal to the root. Each subtree is itself a binary\
    search tree.";
    BinarySearchTree *bst = buildTreeFromString(str);
    bst->print();
    cout << endl;
    cout << "b = " << std::to_string(bst->search("b")) << endl; // 6 times
    cout << "s = " << std::to_string(bst->search("s")) << endl; // 13 times
    cout << "t = " << std::to_string(bst->search("t")) << endl; // 24 times
    system("pause");
    return 1;
    */
}
