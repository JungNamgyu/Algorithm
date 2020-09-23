// 7793. 오! 나의 여신님

#include <iostream>
#include <queue>
using namespace std;

queue <int> Soo_Q, Devil_Q;
int yy[] = { -1,0,1,0 }, xx[] = { 0,1,0,-1 };

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N, M;
		cin >> N >> M;
		char map[51][51];
		int Soo_cnt[51][51] = { 0 }, Devil_cnt[51][51] = { 0 }, D[2]; //D[0]=D.y, D[1]=D.x
		for (int j = 0; j < N; j++) cin >> map[j];
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[j][k] == 'D') D[0] = j, D[1] = k;
				if (map[j][k] == 'S') Soo_Q.push(j), Soo_Q.push(k);
				if (map[j][k] == '*') Devil_Q.push(j), Devil_Q.push(k);
			}
		}
		while (!Devil_Q.empty()) {
			int qy = Devil_Q.front(); Devil_Q.pop();
			int qx = Devil_Q.front(); Devil_Q.pop();
			for (int j = 0; j < 4; j++) {
				int y = qy + yy[j], x = qx + xx[j];
				if (0 <= y && y < N && 0 <= x && x < M) {
					if (map[y][x] == '.' || map[y][x] == 'S' ) {
						if (Devil_cnt[y][x] == 0) {
							Devil_Q.push(y), Devil_Q.push(x);
							Devil_cnt[y][x] = Devil_cnt[qy][qx] + 1;
						}
					}
				}
			}
		}
		while (!Soo_Q.empty()) {
			int qy = Soo_Q.front(); Soo_Q.pop();
			int qx = Soo_Q.front(); Soo_Q.pop();
			for (int j = 0; j < 4; j++) {
				int y = qy + yy[j], x = qx + xx[j];
				if (0 <= y && y < N && 0 <= x && x < M) {
					if (map[y][x] == 'D' || map[y][x] == '.') {
						if (Soo_cnt[y][x] == 0){
							if (Soo_cnt[qy][qx] + 1 < Devil_cnt[y][x] || Devil_cnt[y][x] == 0) {
								Soo_Q.push(y), Soo_Q.push(x);
								Soo_cnt[y][x] = Soo_cnt[qy][qx] + 1;
							}
						}
					}
				}
			}
		}
		if (!Soo_cnt[D[0]][D[1]])
			cout << '#' << i << " GAME OVER" << endl;
		else
			cout << '#' << i << ' ' << Soo_cnt[D[0]][D[1]] << endl;
	}
	return 0;
}