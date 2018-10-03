#include <iostream>
#include <string>
using namespace std;
char* c(string s1, string s2)
{
	int l1 = (int)s1.length();
	int l2 = (int)s2.length();
	if (l1 > l2)
	{
		return 0;
	}
	for (int i = 0; i <= l2 - l1; i++)
	{
		int j = 0;
		while (j < l1)
		{
			if (s2[i + j] != s1[j])
			{
				break;
			}
			else
			{
				j++;
			}
		}
		if (j == l1)
		{
			return &s2[i];
		}
	}
	return 0;
}
int main()
{
	string s1, s2;
	char* ptr;
	cout << "Nhap chuoi thu nhat:" << endl;
	getline(cin, s1);
	cout << "Nhap chuoi thu hai:" << endl;
	getline(cin, s2);
	ptr = c(s1, s2);
	if (ptr != 0)
	{
		cout << "Dia chi can biet la: " << (void *)ptr << endl;
	}
	else
	{
		cout << "Chuoi 1 khong phai la chuoi con cua chuoi 2!" << endl;
	}
	system("pause");
	return 0;
}