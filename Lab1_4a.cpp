#include <iostream>
#include <string>
using namespace std;
int a(string s1, string s2)
{
	if (s1 == s2)
	{
		return 0;
	}
	int l = (s1.length() < s2.length()) ? s1.length() : s2.length();
	for (int i = 0; i < l; i++)
	{
		if (s1[i] != s2[i])
		{
			return i + 1;
		}
	}
	return l + 1;
}
int main()
{
	string s1, s2;
	int n;
	cout << "Nhap chuoi dau tien:" << endl;
	getline(cin, s1);
	cout << "Nhap chuoi thu hai:" << endl;
	getline(cin, s2);
	n = a(s1, s2);
	cout << "Ket qua la: " << n << endl;
	system("pause");
	return 0;
}