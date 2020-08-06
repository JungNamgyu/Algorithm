// 7733. 치즈 도둑

#include <iostream>
#include <queue>
using namespace std;

queue <int> Q;
bool ch[101][101];
int N, Map[101][101], yy[] = { -1,0,1,0 }, xx[] = { 0, 1, 0,-1 };

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a > b ? b : a; }

int BFS(int y, int x, int day) {
	Q.push(y), Q.push(x);
	while (!Q.empty()) {
		int qy = Q.front(); Q.pop();
		int qx = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int iy = qy + yy[i], ix = qx + xx[i];
			if (0 < iy && iy <= N && 0 < ix && ix <= N) {
				if (!ch[iy][ix] && day < Map[iy][ix]) {
					ch[iy][ix] = true;
					Q.push(iy), Q.push(ix);
				}
			}
		}
	}
	return 1;
}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int Max = 1;
		cin >> N;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) cin >> Map[j][k];
		}
		for (int day = 1; day <= 100; day++) {
			int cheeze = 0;
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= N; k++) ch[j][k] = false;
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= N; k++)
					if (day < Map[j][k] && !ch[j][k]) cheeze += BFS(j, k, day);
			if (Max < cheeze) Max = cheeze;
		}
		cout << "#" << i << " " << Max << "\n";
	}
	return 0;
}