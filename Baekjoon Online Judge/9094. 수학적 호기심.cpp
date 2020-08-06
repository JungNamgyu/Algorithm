#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, cnt = 0;
		cin >> n >> m;
		for (int a = 1; a < n; a++) {
			for (int b = a + 1; b < n; b++) {
				if (((a * a) + (b * b) + m) % (a * b) == 0)
					cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}