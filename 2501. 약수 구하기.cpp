#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n, k, d[10001], cnt = 1;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			d[cnt++] = i;
			if (n / i != i)
				d[cnt++] = n / i;
		}
	}
	sort(d + 1, d + 1 + cnt);
	cout << (k > cnt ? 0 : d[k + 1]);
	return 0;
}