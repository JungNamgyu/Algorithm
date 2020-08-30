#include<iostream>
using namespace std;

bool Dp[102][13][32];
// [i][j][k] = 1900 + i 년 j월 k일에서 시작할 경우 필승법 존재 유무 (1: 필패, 0: 필승)
int M[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int next_M[] = { 0, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31 };

bool isLeapYear(int x) {
	return (x % 4 == 0 && x % 100 != 0 || x % 400 == 0);
}

void init() {
	Dp[101][11][2] = true;

	for (int i = 101; i >= 0; i--) { // 1900 + i 년
		for (int j = (i == 101 ? 10 : 12); j >= 1; j--) { // 2001년이면 10월 시작, 나머지는 12월 시작

			int day = M[j] + (j == 2 && isLeapYear(1900 + i) ? 1 : 0);
			for (int k = day; k >= 1; k--) {
				bool check;
				if (k == day)
					check = (j == 12 ? Dp[i + 1][1][1] : Dp[i][j + 1][1]);
				else
					check = Dp[i][j][k + 1];

				if (k <= next_M[j] + (j == 1 && isLeapYear(1900 + i) ? 1 : 0))
					check = check || (j == 12 ? Dp[i + 1][1][k] : Dp[i][j + 1][k]);
				
				Dp[i][j][k] = !check;
			}
		}
	}
}

int main() {
	init();

	int T;
	cin >> T;
	while (T--) {
		int Y, M, D;
		cin >> Y >> M >> D;
		cout << (!Dp[Y - 1900][M][D] ? "YES" : "NO") << endl;
	}
	
	return 0;
}