#include <cmath>
#include <iostream>

#include "binarysearchtree.h"

#define MAX_HEAP_ELEMENT 1000

using namespace std;

void reheapUp(int *&maxHeap, int pos, int size)
{
    if (pos <= 0 || pos >= size)
        return;
    int parent = (pos - 1) / 2;
    if (maxHeap[pos] < maxHeap[parent])
        return;
    swap(maxHeap[pos], maxHeap[parent]);
    reheapUp(maxHeap, parent, size);
}

int *buildHeap(int *arr, int size)
{
    int *maxHeap = new int[MAX_HEAP_ELEMENT];
    for (int i = 0; i < size; ++i) {
        maxHeap[i] = arr[i];
        reheapUp(maxHeap, i, i + 1);
    }
    return maxHeap;
}

//Cau_1
void printHeap(int *heap, int size)
{
    if (size <= 0)
        return;
    int height = int(log(size) / log(2)) + 1;
    for (int i = 0; i < size; ++i) {
        int level = int(log(i + 1) / log(2));
        int space = int(pow(2, height - level - 2));
        for (int i = 0; i < space; ++i) {
            cout << "   ";
        }
        for (int i = 1; i < space; ++i) {
            cout << "---";
        }
        if (heap[i] < 10)
            cout << "0";
        if (heap[i] < 100)
            cout << "0";
        cout << heap[i];
        for (int i = 1; i < space; ++i) {
            cout << "---";
        }
        for (int i = 0; i < space; ++i) {
            cout << "   ";
        }
        cout << "   ";
        if (i == int(pow(2, level + 1) - 2))
            cout << endl;
    }
    cout << endl;
}

void buildHeapFromSubroot(int *&maxHeap, int &size, TreeNode *node)
{
    if (node == nullptr)
        return;
    if (node->getRight() != nullptr)
        buildHeapFromSubroot(maxHeap, size, node->getRight());
    maxHeap[size] = node->getData();
    ++size;
    if (node->getLeft() != nullptr)
        buildHeapFromSubroot(maxHeap, size, node->getLeft());
}

//Cau_2
int *buildHeapFromBST(BinarySearchTree *bst, int &size)
{
    if (bst == nullptr)
        return nullptr;
    int *maxHeap = new int[MAX_HEAP_ELEMENT];
    size = 0;
    buildHeapFromSubroot(maxHeap, size, bst->root);
    return maxHeap;
}

//Cau_3a
long long int f1(int *key, int size)
{
    long long int hf = 7719;
    long long int hash = 0;
    for (int i = 0; i < size; ++i) {
        long long int p = 1;
        for (int j = 0; j < i; ++j) {
            p *= key[i];
            p %= hf;
        }
        p *= 7;
        p %= hf;
        hash += p;
        hash %= hf;
    }
    return hash;
}

//Cau_3b
long long int f2(int *key, int size)
{
    long long int hf = 7719;
    long long int hash = 0;
    for (int i = 0; i < size; ++i) {
        long long int p = 1;
        for (int j = 0; j < key[i]; ++j) {
            p *= key[i];
            p %= hf;
        }
        p *= 7;
        p %= hf;
        hash += p;
        hash %= hf;
    }
    return hash;
}

//Cau_4a
void reheapUp(int *&maxHeap, int position)
{
    if (position > 0) {
        int parent = (position - 1) / 2;
        if (maxHeap[position] > maxHeap[parent]) {
            swap(maxHeap[position], maxHeap[parent]);
            reheapUp(maxHeap, position);
        }
    }
}

void reheapDown(int *&maxHeap, int position, int size)
{
    if (position < 0 || position >= size)
        return;
    int leftChild = position * 2 + 1;
    int rightChild = position * 2 + 2;
    int largeChild = -1;
    if (leftChild <= size - 1) {
        if (rightChild <= size - 1 && maxHeap[rightChild] > maxHeap[leftChild]) {
            largeChild = rightChild;
        } else {
            largeChild = leftChild;
        }
        if (maxHeap[largeChild] > maxHeap[position]) {
            swap(maxHeap[largeChild], maxHeap[position]);
            reheapDown(maxHeap, largeChild, size);
        }
    }
}

void reheapDownMinHeap(int *&minHeap, int pos, int size)
{
    if (pos < 0 || pos > (size - 2) / 2)
        return;
    int l = 2 * pos + 1;
    if (l >= size)
        return;
    int posMin = l;
    int r = l + 1;
    if (2 * pos + 2 < size) {
        if (minHeap[r] < minHeap[posMin]) {
            posMin = r;
        }
    }
    if (minHeap[pos] > minHeap[posMin]) {
        swap(minHeap[pos], minHeap[posMin]);
        reheapDownMinHeap(minHeap, posMin, size);
    }
}

//Cau4_b
void maxHeapToMinHeap(int *&maxHeap, int size)
{
    for (int i = (size - 1) / 2; i >= 0; --i)
        reheapDownMinHeap(maxHeap, i, size);
}

int main()
{
    int arr[8] = {473, 309, 286, 598, 438, 663, 948, 424};
    BinarySearchTree *bst = new BinarySearchTree;
    for (int i = 0; i < 8; ++i) {
        TreeNode *temp = new TreeNode(arr[i]);
        bst->insert(temp);
    }
    bst->print();
    int size = 0;
    int *maxHeap = buildHeapFromBST(bst, size);
    printHeap(maxHeap, size);
    maxHeapToMinHeap(maxHeap, size);
    printHeap(maxHeap, size);
    return 0;
}
