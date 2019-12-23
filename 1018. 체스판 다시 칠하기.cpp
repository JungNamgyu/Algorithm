#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string Board[51];
int N, M, Min = 2e9;

int setChess(int y, int x, char c1, char c2) {
	int paint = 0;
	for (int i = y; i < y + 8; i += 2) {
		for (int j = x; j < x + 8; j += 2) {
			if (Board[i][j] != c1)
				paint++;
			if (Board[i][j + 1] != c2)
				paint++;
		}
	}
	for (int i = y + 1; i < y + 8; i += 2) {
		for (int j = x; j < x + 8; j += 2) {
			if (Board[i][j] != c2)
				paint++;
			if (Board[i][j + 1] != c1)
				paint++;
		}
	}
	return paint;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> Board[i];
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			Min = min(Min, min(setChess(i, j, 'W', 'B'), setChess(i, j, 'B', 'W')));
		}
	}
	cout << Min;
	return 0;
}