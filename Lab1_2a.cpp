#include <iostream>
using namespace std;
void nhapMatran(int *arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << "Nhap phan tu tai hang " << i + 1 << ", cot " << j + 1 << ":";
			cin >> *(arr + r*i + j);
		}
	}
}
void hienthiMatran(int *arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << *(arr + r * i + j) << "\t";
		}
		cout << endl;
	}
}
void nhanMatran(int *a, int ar, int ac, int *b, int br, int bc, int *c)
{
	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < bc; j++)
		{
			*(c + ar * i + j) = 0;
		}
	}
	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < bc; j++)
		{
			for (int k = 0; k < ac; k++)
			{
				*(c + ar * i + j) += (*(a + ar * i + k)) * (*(b + ac * k + j));
			}
		}
	}
}
int main()
{
	const int ar = 3;
	const int ac = 3;
	const int br = 3;
	const int bc = 3;
	int a[ar][ac] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	int b[br][bc] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	int c[ar][bc];
	/*
	cout << "Nhap vao ma tran A[" << ar << "][" << ac << "]:" << endl;
	nhapMatran(*a, ar, ac);
	cout << "Nhap vao ma tran B[" << br << "][" << bc << "]:" << endl;
	nhapMatran(*b, br, bc);
	*/
	cout << "Ma tran A:" << endl;
	hienthiMatran(*a, ar, ac);
	cout << "Ma tran B:" << endl;
	hienthiMatran(*b, ar, ac);
	cout << "Ma tran C = A*B:" << endl;
	nhanMatran(*a, ar, ac, *b, br, bc, *c);
	hienthiMatran(*c, ar, bc);
	system("pause");
	return 0;
}