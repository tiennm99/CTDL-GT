#include <iostream>
using namespace std;
void draw_ch(int k)
{
	if (k > 1)
	{
		cout << "_";
		draw_ch(k - 1);
	}
}
void draw_num(int k, int n)
{
	if (k <= n)
	{
		cout << k;
		draw_num(k + 1, n);
	}
}
void draw1Line(int k, int n, bool b)
{
	draw_ch(k);
	draw_num(k, n);
	cout << endl;
	if (b == 0)
	{
		if (k > n / 2 + 1)
		{
			draw1Line(k - 1, n, 0);
		}
		else
		{
			if (n % 2)
			{
				draw1Line(k + 1, n, 1);
			}
			else
			{
				draw1Line(k, n, 1);
			}
		}
	}
	else
	{
		if (k >= n)
		{
			return;
		}
		else
		{
			draw1Line(k + 1, n, 1);
		}
	}
}
void recursiveTriangle(int N)
{
	draw1Line(N, N, 0);
}
void loopTriangle(int N)
{
	int k, i;
	k = N;
	for (; k > N/2; k--)
	{
		i = 1;
		for (; i < k; i++)
		{
			cout << "_";
		}
		for (; i <= N; i++)
		{
			cout << i;
		}
		cout << endl;
	}
	if (N % 2)
	{
		k+= 2;
	}
	else
	{
		k++;
	}
	for (; k <= N; k++)
	{
		i = 1;
		for (; i < k; i++)
		{
			cout << "_";
		}
		for (; i <= N; i++)
		{
			cout << i;
		}
		cout << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	recursiveTriangle(n);
	loopTriangle(n);
	system("pause");
	return 0;
}