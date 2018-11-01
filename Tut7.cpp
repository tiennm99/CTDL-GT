#include <cmath>
#include <iostream>

using namespace std;

template <class T>
void printHeap(T *heap, int cnt, int pos)
{
    if (cnt < 1)
        return;
    if (pos >= cnt) {
        for (int i = 1; i <= log(pos + 1) / log(2); ++i)
            cout << "\t";
        cout << "NULL" << endl;
        return;
    }
    printHeap(heap, cnt, 2 * pos + 2);
    for (int i = 1; i <= log(pos + 1) / log(2); ++i)
        cout << "\t";
    cout << heap[pos] << endl;
    printHeap(heap, cnt, 2 * pos + 1);
}

bool IsMaxHeap(int *arr, int size)
{
    for (int i = size - 1; i > 0; --i) {
        if (arr[i] > arr[(i - 1) / 2])
            return false;
    }
    return true;
}

void reheapDown(int *&maxHeap, int pos, int size)
{
    if (2 * pos + 1 >= size)
        return;
    int posMax = 2 * pos + 1;
    if (2 * pos + 2 < size) {
        if (maxHeap[2 * pos + 2] > maxHeap[posMax]) {
            posMax = 2 * pos + 2;
        }
    }
    if (maxHeap[pos] < maxHeap[posMax]) {
        swap(maxHeap[pos], maxHeap[posMax]);
        reheapDown(maxHeap, posMax, size);
    }
}

bool DeleteHeapNode(int *&maxHeap, int delPosition, int &size, int &dataOut)
{
    if (delPosition < 0 || delPosition >= size)
        return false;
    dataOut = maxHeap[delPosition];
    maxHeap[delPosition] = maxHeap[size - 1];
    --size;
    reheapDown(maxHeap, delPosition, size);
    return true;
}

int main()
{
    int maxHeap[6] = {1200, 523, 1001, 321, 14, 131};
    int *test1 = new int[8] {77, 60, 35, 45, 56, 4, 34, 22};
    int test2[9] = {9, 8, 4, 7, 5, 2, 3, 1, 6};
    printHeap(test1, 8, 0);
    printHeap(test2, 9, 0);
    if (IsMaxHeap(test1, 8))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    int out;
    int size = 8;
    DeleteHeapNode(test1, 0, size, out);
    if (DeleteHeapNode(test1, 0, size, out)) {
        cout << size << "\t" << out << endl;
    }
    printHeap(test1, size, 0);
    return 0;
}
