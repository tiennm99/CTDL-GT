#include <iostream>
using namespace std;
void nhapMatran(int **arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << "Nhap phan tu tai hang " << i + 1 << ", cot " << j + 1 << ":";
			cin >> arr[i][j];
		}
	}
}
void hienthiMatran(int **arr, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
bool nhanMatran(int **a, int ar, int ac, int **b, int br, int bc, int **c, int &cr, int &cc)
{
	if (ac == br)
	{
		for (int i = 0; i < cr; i++)
		{
			for (int j = 0; j < cc; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k < ac; k++)
				{
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int **a, **b, **c;
	int ar, ac, br, bc, cr, cc;
	cout << "Nhap vao so hang cua ma tran A:";
	cin >> ar;
	cout << "Nhap vao so cot cua ma tran A:";
	cin >> ac;
	a = new int*[ar];
	for (int i = 0; i < ar; i++)
	{
		a[i] = new int[ac];
	}
	nhapMatran(a, ar, ac);
	cout << "Nhap vao so hang cua ma tran B:";
	cin >> br;
	cout << "Nhap vao so cot cua ma tran B:";
	cin >> bc;
	b = new int*[br];
	for (int i = 0; i < br; i++)
	{
		b[i] = new int[bc];
	}
	nhapMatran(b, br, bc);
	cr = ar;
	cc = bc;
	c = new int*[cr];
	for (int i = 0; i < cr; i++)
	{
		c[i] = new int[cc];
	}
	cout << "Ma tran A[" << ar << "][" << ac << "]:" << endl;
	hienthiMatran(a, ar, ac);
	cout << "Ma tran B[" << br << "][" << bc << "]:" << endl;
	hienthiMatran(b, ar, ac);
	cout << "Ma tran C = A*B:" << endl;
	if (nhanMatran(a, ar, ac, b, br, bc, c, cr, cc))
	{
		hienthiMatran(c, cr, cc);
	}
	else
	{
		cout << "Khong the nhan hai ma tran voi kich co " << ar << "*" << ac << " va " << br << "*" << bc << "!" << endl;
	}
	system("pause");
	return 0;
}