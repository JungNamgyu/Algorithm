// 17135. 캐슬 디펜스

#include<cstdio>
#include<algorithm>
using namespace std;

int N, M, D, map[15][15];
int defense(int, int, int);
struct Z { int r, c, dis = 11; };
inline int dis(int r1, int c1, int r2, int c2) { return abs(r1 - r2) + abs(c1 - c2); }

int main() {
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	int Max = 0;
	for (int i = 0; i < M; i++)
		for (int j = i + 1; j < M; j++)
			for (int k = j + 1; k < M; k++)
				Max = max(Max, defense(i, j, k));

	printf("%d", Max);
	return 0;
}

int defense(int a, int b, int c) {
	int kill = 0;
	bool M_ch[15][15] = { false };
	for (int t = N; t > 0; t--) {
		Z a_k, b_k, c_k;
		for (int j = 0; j < M; j++) {
			for (int i = t - 1; i >= max(0, t - D); i--) {
				if (map[i][j] && !M_ch[i][j]) {
					if (a_k.dis > dis(t, a, i, j) && D >= dis(t, a, i, j)) {
						a_k.r = i, a_k.c = j;
						a_k.dis = dis(t, a, i, j);
					}
					if (b_k.dis > dis(t, b, i, j) && D >= dis(t, b, i, j)) {
						b_k.r = i, b_k.c = j;
						b_k.dis = dis(t, b, i, j);
					}
					if (c_k.dis > dis(t, c, i, j) && D >= dis(t, c, i, j)) {
						c_k.r = i, c_k.c = j;
						c_k.dis = dis(t, c, i, j);
					}
				}
			}
		}
		if (a_k.dis < 11) M_ch[a_k.r][a_k.c] = true;
		if (b_k.dis < 11) M_ch[b_k.r][b_k.c] = true;
		if (c_k.dis < 11) M_ch[c_k.r][c_k.c] = true;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (M_ch[i][j]) kill++;
	return kill;
}