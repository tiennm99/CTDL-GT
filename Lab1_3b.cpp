#include <iostream>
using namespace std;
long pow(int n, int m)
{
	if (m == 0)
	{
		return 1;
	}
	else
	{
		return n * pow(n, m - 1);
	}
}
int main()
{
	int n, m;
	long p;
	cout << "Nhap co so: ";
	cin >> n;
	cout << "Nhap so mu: ";
	cin >> m;
	p = pow(n, m);
	cout << "n ^ m = " << p << endl;
	system("pause");
	return 0;
}