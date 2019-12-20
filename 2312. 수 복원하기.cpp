#include<iostream>
using namespace std;

int p[10000], prime[100001], cnt;

int main() {
	for (int i = 2; i < 100001; i++) {
		if (!prime[i]) {
			p[cnt++] = i;
			for (int j = i + i; j < 100001; j += i)
				prime[j] = true;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < cnt; i++) {
			int cn = 0;
			if (n % p[i] == 0) {
				while (n % p[i] == 0) {
					n /= p[i];
					cn++;
				}
				cout << p[i] << " " << cn << endl;
			}
		}
	}
	return 0;
}