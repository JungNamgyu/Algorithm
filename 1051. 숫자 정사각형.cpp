#include<iostream>
#include<string>
using namespace std;

string S[50];
int N, M, Max = 0;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> S[i];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int sz = (N - i > M - j ? M - j : N - i);
			for (int k = 1; k < sz; k++) {
				if (S[i][j] == S[i + k][j] && S[i][j] == S[i][j + k] && S[i][j] == S[i + k][j + k]) {
					if (Max < k) Max = k;
				}
			}
		}
	}

	cout << (Max + 1) * (Max + 1);
	return 0;
}