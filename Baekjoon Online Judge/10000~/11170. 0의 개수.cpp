#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M, cnt = 0;
		cin >> N >> M;
		for (int i = N; i <= M; i++) {
			int n = i;
			do {
				if (n % 10 == 0) cnt++;
				if (n) n /= 10;
			} while (n);
		}
		cout << cnt << endl;
	}
	return 0;
}