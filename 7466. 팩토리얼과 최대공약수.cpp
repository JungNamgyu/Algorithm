// 7466. 팩토리얼과 최대공약수

#include<iostream>
#include<math.h>
using namespace std;

void prime(int k, int x, int kp[], int &kcnt) {
	bool ch = true;
	int i, x_sqrt = sqrt(x);
	for (i = 2; i <= x_sqrt; i++)
		if (x % i == 0) ch = false;
	if (ch) {
		while (!(k % x)) {
			k /= x;
			kp[kcnt++] = x;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n, k;
		cin >> n >> k;
		int ans = 1, kcnt = 1, kp[30] = { 1, };
		for (int j = 2; j < sqrt(k); j++) {
			if (k % j == 0) {
				prime(k, j, kp, kcnt);
				prime(k, k / j, kp, kcnt);
			}
		}
		for (int fact = 1, st = 0; fact <= n; fact++) {
			int fact_copy = fact;
			for (int j = st; j < kcnt; j++) {
				if(!(fact_copy % kp[j])){
					ans *= kp[j];
					fact_copy /= kp[j];
					swap(kp[st++], kp[j]);
				}
			}
			if (st == kcnt) break;
		}
		cout << "#" << i << " " << ans << "\n";
	}

	return 0;
}