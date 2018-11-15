#include <iostream>

using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int *&arr, int left, int right, int size)
{
    int pivot = arr[left];
    int i = left;
    for (int j = left + 1; j <= right; ++j) {
        if (arr[j] < pivot) {
            ++i;
            if (i != j) {
                swap(arr[i], arr[j]);
                printArray(arr, size);
            }
        }
    }
    if (i != left) {
        swap(arr[left], arr[i]);
        printArray(arr, size);
    }
    return i;
}

void recursiveQuickSort(int *&arr, int left, int right, int size)
{
    if (left < right) {
        int pivot = partition(arr, left, right, size);
        recursiveQuickSort(arr, left, pivot - 1, size);
        recursiveQuickSort(arr, pivot + 1, right, size);
    }
}

//Ham quickSort su dung phan tu tan cung ben trai lam phan tu chot
void quickSort(int *&arr, int size)
{
    recursiveQuickSort(arr, 0, size - 1, size);
}

int partition2(int *&arr, int left, int right, int size)
{
    int pivot = arr[right];
    int i = right;
    for (int j = right - 1; j >= left; --j) {
        if (arr[j] > pivot) {
            --i;
            if (i != j) {
                swap(arr[i], arr[j]);
                printArray(arr, size);
            }
        }
    }
    if (i != right) {
        swap(arr[right], arr[i]);
        printArray(arr, size);
    }
    return i;
}

void recursiveQuickSort2(int *&arr, int left, int right, int size)
{
    if (left < right) {
        int pivot = partition2(arr, left, right, size);
        recursiveQuickSort2(arr, left, pivot - 1, size);
        recursiveQuickSort2(arr, pivot + 1, right, size);
    }
}

//Ham quickSort2 su dung phan tu tan cung ben phai lam phan tu chot
void quickSort2(int *&arr, int size)
{
    recursiveQuickSort2(arr, 0, size - 1, size);
}

int main()
{
    int *arr = new int[9] {53, 59, 56, 52, 55, 58, 51, 57, 54};
    printArray(arr, 9);
    quickSort(arr, 9);
    cout << "==========================" << endl;
    arr = new int[9] {53, 59, 56, 52, 55, 58, 51, 57, 54};
    printArray(arr, 9);
    quickSort2(arr, 9);
    return 0;
}
