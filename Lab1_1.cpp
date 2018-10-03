#include <iostream>
using namespace std;
bool isLeapYear(int n)
{
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
	{
		return true;
	}
	return false;
}
int main()
{
	int n;
	cout << "Nhap so nam:" << endl;
	cin >> n;
	if (isLeapYear(n))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	cout << endl;
	system("pause");
	return 0;
}