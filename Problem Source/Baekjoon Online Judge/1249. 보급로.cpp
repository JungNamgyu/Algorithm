// 1249. 보급로

#include <iostream>
#include <queue>
using namespace std;

queue <int> Q;
char Map[101][101];
int N, Time[101][101];
int yy[] = { -1,0,1,0 }, xx[] = { 0,1,0,-1 };

int BFS() {
	while (!Q.empty()) {
		int y = Q.front(); Q.pop();
		int x = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int iy = y + yy[i], ix = x + xx[i];
			if (0 <= iy && iy < N && 0 <= ix && ix < N) {
				if ((Time[y][x] + (Map[iy][ix] - '0')) < Time[iy][ix]) {
					Q.push(iy), Q.push(ix);
					Time[iy][ix] = Time[y][x] + (Map[iy][ix] - '0');
				}
			}
		}
	}
	return Time[N - 1][N - 1];
}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) Time[j][k] = 2e10;
		for (int j = 0; j < N; j++) cin >> Map[j];
		Q.push(0); Q.push(0);
		Time[0][0] = Map[0][0] - '0';
		cout << "#" << i << " " << BFS() << "\n";
	}
	return 0;
}