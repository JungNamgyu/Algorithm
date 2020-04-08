#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;

string Set[15];
ll Dp[32768][100];
int N, K, T[51], L[15], S[15];


ll gcd(ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}

int main() {
	int i, j, k;

	cin >> N;
	for (i = 0; i < N; i++)
		cin >> Set[i];
	cin >> K;
	for (i = 0; i < N; i++) {
		L[i] = Set[i].size();
		for (S[i] = (Set[i][0] - '0') % K, j = 1; j < L[i]; j++)
			S[i] = (S[i] * 10 + (Set[i][j] - '0')) % K;
	}

	for (T[0] = 1, i = 1; i <= 50; i++)
		T[i] = (T[i - 1] * 10) % K;

	Dp[0][0] = 1;
	for (i = 0; i < (1 << N); i++) {
		for (j = 0; j < K; j++) {
			if (Dp[i][j]) {
				for (k = 0; k < N; k++) {
					if (!(i & (1 << k))) {
						int m = (((j * T[L[k]]) % K) + S[k]) % K;
						Dp[i | (1 << k)][m] += Dp[i][j];
					}
				}
			}
		}
	}

	ll p = Dp[(1 << N) - 1][0], q = 1;
	if (p == 0)
		cout << "0/1";
	else {
		for (i = 2; i <= N; i++) q *= i;
		ll GCD = gcd(p, q);
		cout << p / GCD << "/" << q / GCD;
	}
	return 0;
}