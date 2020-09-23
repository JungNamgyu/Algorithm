#include<iostream>
using namespace std;

int main() {
	int N, cnt = 0;
	cin >> N;
	for (int A = 1; A <= 500; A++) {
		for (int B = 1; B * B + N <= A * A; B++)
			if (B * B + N == A * A) cnt++;
	}
	cout << cnt;
	return 0;
}