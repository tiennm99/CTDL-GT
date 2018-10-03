#include <iostream>
using namespace std;
bool isPrime(int num) {
	if (num < 2) {
		return false;
	}
	int i;
	for (i = 2; i*i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}
void onePrime(int * arr, int n) {
	if (n == 0)
	{
		return;
	}
	if (isPrime(arr[n - 1]))
	{
		cout << arr[n - 1] << endl;
		return;
	}
	onePrime(arr, n - 1);
}
void allPrime(int * arr, int n) {
	if (n == 0)
	{
		cout << endl;
		return;
	}
	if (isPrime(arr[n - 1]))
	{
		cout << arr[n - 1] << " ";
	}
	allPrime(arr, n - 1);
}
int main()
{
	int arr[] = {1, 3, 5, 7, 9};
	onePrime(arr, 5);
	allPrime(arr, 5);
	system("pause");
	return 0;
}