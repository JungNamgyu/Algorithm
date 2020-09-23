#include<iostream>
using namespace std;

int main() {
	int R, C, W, Ans = 0, pascal[31][31] = { 1, };

	cin >> R >> C >> W;
	for (int i = 1; i < R + W; i++)
		for (int j = 1; j <= i; j++)
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
	for (int i = R; i < R + W; i++)
		for (int j = C; j - C <= i - R; j++)
			Ans += pascal[i][j];
	cout << Ans;

	return 0;
}