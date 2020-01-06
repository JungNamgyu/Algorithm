#include<iostream>
using namespace std;

int main() {
	int N, inx = 1;
	cin >> N;
	for (int i = 11; i <= N; i = i * 10 + 1)
		inx++;
	cout << inx;
	return 0;
}