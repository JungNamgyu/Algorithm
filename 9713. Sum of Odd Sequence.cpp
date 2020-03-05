#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, sum = 0;
		cin >> N;
		for (int i = 1; i <= N; i += 2) sum += i;
		cout << sum << endl;
	}
	return 0;
}