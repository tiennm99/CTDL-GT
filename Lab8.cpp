#include <iostream>
#include <cstring>

using namespace std;

void straightInsertSort(int *&arr, int size)
{
    if (size > 1) {
        int i = 1;
        while (i < size) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && key < arr[j]) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
            ++i;
        }
    }
}

void sortSegment(int *&arr, int size, int seg, int k)
{
    int i = seg + k;
    while (i < size) {
        int key = arr[i];
        int j = i - k;
        while (j >= 0 && key < arr[j]) {
            arr[j + k] = arr[j];
            j -= k;
        }
        arr[j + k] = key;
        i += k;
    }
}

void shellSort(int *&arr, int size)
{
    int k = 3;  //first_incremental_value = 3, can be 7, 15,...
    while (k >= 1) {
        int seg = 1;
        while (seg <= k) {
            sortSegment(arr, size, seg, k);
            ++seg;
        }
        k = (k - 1) / 2;
    }
}

void straightSelectionSort(int *&arr, int size)
{
    int i = 0;
    while (i < size - 1) {
        int min = i;
        int j = i + 1;
        while (j < size) {
            if (arr[j] < arr[min])
                min = j;
            ++j;
        }
        swap(arr[i], arr[min]);
        ++i;
    }
}

void reheapDown(int *&maxHeap, int size, int pos)
{
    if (2 * pos + 1 >= size)
        return;
    int posMax = 2 * pos + 1;
    if (2 * pos + 2 < size) {
        if (maxHeap[2 * pos + 2] > maxHeap[posMax])
            posMax = 2 * pos + 2;
    }
    if (maxHeap[pos] < maxHeap[posMax]) {
        swap(maxHeap[pos], maxHeap[posMax]);
        reheapDown(maxHeap, posMax, size);
    }
}

void heapSort(int *&arr, int size)
{
    int pos = size / 2 - 1;
    while (pos >= 0) {
        reheapDown(arr, size, pos);
        --pos;
    }
    int end = size - 1;
    while (end > 0) {
        swap(arr[0], arr[end]);
        --end;
        reheapDown(arr, end + 1, 0);
    }
}

void bubbleSort(int *&arr, int size)
{
    int i = 0;
    bool flag = false;
    while (i < size && flag == false) {
        int j = size - 1;
        flag = true;
        while (j > i) {
            if (arr[j] < arr[j - 1]) {
                flag = false;
                swap(arr[j], arr[j - 1]);
            }
            --j;
        }
        ++i;
    }
}

int partition(int *&arr, int l, int r)
{
    int pivot = arr[l];
    int i = l;
    for (int j = l + 1; j <= r; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[i]);
    return i;
}

void recursiveQuickSort(int *&arr, int l, int r)
{
    if (l < r) {
        int pivot = partition(arr, l, r);
        recursiveQuickSort(arr, l, pivot - 1);
        recursiveQuickSort(arr, pivot + 1, r);
    }
}

void quickSort(int *&arr, int size)
{
    recursiveQuickSort(arr, 0, size - 1);
}

void merge(int *&arr, int l, int m, int r)
{
    int size1 = m - l + 1;
    int size2 = r - m;
    int *sublist1 = new int[size1];
    int *sublist2 = new int[size2];
    memcpy(sublist1, arr + l, size1 * sizeof(int));
    memcpy(sublist2, arr + m + 1, size2 * sizeof(int));
    int i = 0;
    int j = 0;
    int k = l;
    while (i < size1 && j < size2) {
        if (sublist1[i] <= sublist2[j]) {
            arr[k] = sublist1[i];
            ++i;
        } else {
            arr[k] = sublist2[j];
            ++j;
        }
        ++k;
    }
    while (i < size1) {
        arr[k] = sublist1[i];
        ++i;
        ++k;
    }
    while (j < size2) {
        arr[k] = sublist2[j];
        ++j;
        ++k;
    }
}

void recursiveMergeSort(int *&arr, int l, int r)
{
    if (l < r) {
        int m = (l + r) / 2;
        recursiveMergeSort(arr, l, m);
        recursiveMergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(int *&arr, int size)
{
    recursiveMergeSort(arr, 0, size - 1);
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int size = 8;
    int *arr = new int[size] {20, 27, 10, 12, 22, 18, 14, 21};
    cout << "Mang ban dau:" << endl;
    printArray(arr, size);
    cout << endl;
    int *tmp = new int[size];

    memcpy(tmp, arr, size * sizeof(int));
    straightInsertSort(tmp, size);
    cout << "Mang sau khi sap xep bang giai thuat straightInsertSort:" << endl;
    printArray(tmp, size);
    cout << endl;

    memcpy(tmp, arr, size * sizeof(int));
    shellSort(tmp, size);
    cout << "Mang sau khi sap xep bang giai thuat shellSort:" << endl;
    printArray(tmp, size);
    cout << endl;

    memcpy(tmp, arr, size * sizeof(int));
    straightSelectionSort(tmp, size);
    cout << "Mang sau khi sap xep bang giai thuat straightSelectionSort:" << endl;
    printArray(tmp, size);
    cout << endl;

    memcpy(tmp, arr, size * sizeof(int));
    heapSort(tmp, size);
    cout << "Mang sau khi sap xep bang giai thuat heapSort:" << endl;
    printArray(tmp, size);
    cout << endl;

    memcpy(tmp, arr, size * sizeof(int));
    bubbleSort(tmp, size);
    cout << "Mang sau khi sap xep bang giai thuat bubbleSort:" << endl;
    printArray(tmp, size);
    cout << endl;

    memcpy(tmp, arr, size * sizeof(int));
    quickSort(tmp, size);
    cout << "Mang sau khi sap xep bang giai thuat quickSort:" << endl;
    printArray(tmp, size);
    cout << endl;

    memcpy(tmp, arr, size * sizeof(int));
    mergeSort(tmp, size);
    cout << "Mang sau khi sap xep bang giai thuat mergeSort:" << endl;
    printArray(tmp, size);
    cout << endl;

    return 0;
}
