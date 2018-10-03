#include <iostream>
using namespace std;
long pow(int n, int m)
{
	long p = 1;
	for (int i = 0; i < m; i++)
	{
		p *= n;
	}
	return p;
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