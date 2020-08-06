#include<iostream>
using namespace std;

int m[5][5];
typedef struct Z {
	int y, x;
}INX;

INX find(int n) {
	INX inx;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (m[i][j] == n) {
				m[i][j] = 0;
				inx.y = i, inx.x = j;
				return inx;
			}
		}
	}
}

int ch(INX inx) {
	int cnt, r, c, ld, rd;
	cnt = r = c = ld = rd = 0;
	for (int i = 0; i < 5; i++)
		if (m[i][inx.x] == 0) r++;
	for (int j = 0; j < 5; j++)
		if (m[inx.y][j] == 0) c++;
	if (inx.x == inx.y) {
		for (int i = 0; i < 5; i++)
			if (m[i][i] == 0) ld++;
	}
	if (inx.x == (4 - inx.y)) {
		for (int i = 0; i < 5; i++)
			if (m[i][4 - i] == 0) rd++;
	}
	if (r == 5) cnt++;
	if (c == 5) cnt++;
	if (ld == 5) cnt++;
	if (rd == 5) cnt++;
	return cnt;
}

int main() {
	int t, i, j, l = 0;
	for (i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) cin >> m[i][j];
	for (t = 0; l < 3; t++) {
		int n;
		cin >> n;
		INX inx = find(n);
		l += ch(inx);
	}
	cout << t;
	return 0;
}