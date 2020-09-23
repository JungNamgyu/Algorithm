// 17281. 야구

#include<iostream>
#include<algorithm>
using namespace std;

int N, P[] = { 1,2,3,4,5,6,7,8,9 }, s[50][10], Max;

int main() {

	cin >> N;
	for (int j = 0; j < N; j++)
		for (int i = 1; i <= 9; i++) cin >> s[j][i];
	do {
		int S = 0, t = 0, p[9];

		for (int i = 0; i < 3; i++) p[i] = P[i + 1];
		p[3] = P[0];
		for (int i = 4; i < 9; i++) p[i] = P[i];

		for (int u = 0; u < N; u++) {
			int out = 0, base[4] = { 0 };
			while (out < 3) {
				base[0] = 1;
				switch (s[u][p[t]]) {
				case 4: S += base[0];
				case 3: S += base[1];
				case 2: S += base[2];
				case 1: S += base[3]; break;
				default: out++;
				}
				for (int j = 0; j < s[u][p[t]]; j++) {
					for (int k = 3; k > 0; k--) base[k] = base[k - 1];
					base[0] = 0;
				}
				t = (t + 1) % 9;
			}
		}
		Max = max(Max, S);
	} while (next_permutation(P + 1, P + 9));
	cout << Max;
	return 0;
}
