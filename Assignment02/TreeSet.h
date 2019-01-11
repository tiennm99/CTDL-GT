#include"AVLNode.h"

class TreeSet
{
private:
    AVLNode *root;
    int count;
    int getHeight(AVLNode *node);
    void setHeight(AVLNode *&node);
    int getBalance(AVLNode *node);
    void recursiveSubSet(TreeSet *&treeSet, AVLNode *node, int fromVal, int toVal);
    AVLNode *recursiveAdd(AVLNode *&node, int val);
    AVLNode *recursiveRemove(AVLNode *&node, int val);
    AVLNode *recursiveCopy(AVLNode *node);
    AVLNode *rotateLeft(AVLNode *&node);
    AVLNode *rotateRight(AVLNode *&node);
    AVLNode *rebalance(AVLNode *&node);
protected:
    void clearRec(AVLNode *root);
public:
    TreeSet();
    ~TreeSet();
    void clear();
    friend ostream &operator<<(ostream &os, const TreeSet &t);
    int add(int val);
    bool contains(int val);
    void copy(const TreeSet &set);
    int first();
    int higher(int val);
    int last();
    int lower(int val);
    int remove(int val);
    TreeSet *subSet(int fromVal, int toVal);
    int size();
};
