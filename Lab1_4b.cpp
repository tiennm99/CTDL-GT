#include <iostream>
#include <string>
using namespace std;
char* b(string s, char c)
{
	int l = (int)s.length();
	for (int i = 0; i < l; i++)
	{
		if (s[i] == c)
		{
			return &s[i];
		}
	}
	return 0;
}
int main()
{
	string s;
	char c;
	char* ptr;
	cout << "Nhap chuoi:" << endl;
	getline(cin, s);
	cout << "Nhap ki tu:" << endl;
	cin >> c;
	ptr = b(s, c);
	if (ptr != 0)
	{
		cout << "Dia chi cua ki tu la: " << (void *) ptr << endl;
	}
	else
	{
		cout << "Khong tim thay ki tu trong chuoi!" << endl;
	}
	system("pause");
	return 0;
}