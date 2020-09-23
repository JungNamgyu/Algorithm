#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

bool t[20];
int N, T[20][20], Min = 2e9;

void Soccer(int n, int x) {
	if (n == N / 2) {
		int start = 0, link = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (t[i] == t[j])
					t[i] ? start += T[i][j] : link += T[i][j];
			}
		}
		Min = min(Min, abs(start - link));
	}
	else {
		for (int i = x; i < N; i++) {
			if (!t[i]) {
				t[i] = true;
				Soccer(n + 1, i + 1);
				t[i] = false;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> T[i][j];
	t[0] = true;
	Soccer(1, 1);
	cout << Min;
	return 0;
}