#include<iostream>
using namespace std;

int main() {
	int n, A[101];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int back;
		cin >> back;
		for (int j = i; j > i - back; j--)
			A[j] = A[j - 1];
		A[i - back] = i;
	}
	for (int i = 1; i <= n; i++)
		cout << A[i] << " ";
	return 0;
}