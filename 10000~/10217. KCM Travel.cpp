#pragma warning(disable:4996)

#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

typedef struct Z {
	int v, c, d;
}NEXT;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M, K;
		scanf("%d%d%d", &N, &M, &K);
		vector< vector<NEXT> > Next(N + 1);
		vector< vector<int> > Cost(N + 1, vector<int>(M + 1, 2e9));
		for (int i = 0; i < K; i++) {
			int u;
			NEXT next;
			scanf("%d%d%d%d", &u, &next.v, &next.c, &next.d);
			Next[u].push_back(next);
		}
		Cost[1][0] = 0;
		queue<int> Q;
		Q.push(1); Q.push(0);
		while (!Q.empty()) {
			int inx = Q.front(); Q.pop();
			int cost = Q.front(); Q.pop();
			int sz = Next[inx].size();
			for (int i = 0; i < sz; i ++) {
				NEXT next = Next[inx][i];
				if (cost + next.c <= M) {
					if (Cost[next.v][cost + next.c] > Cost[inx][cost] + next.d) {
						Cost[next.v][cost + next.c] = Cost[inx][cost] + next.d;
						Q.push(next.v); Q.push(cost + next.c);
					}
				}
			}
		}
		int Min = 2e9;
		for (int i = 0; i <= M; i++)
			Min = min(Min, Cost[N][i]);
		if (Min == 2e9)
			printf("Poor KCM\n");
		else
			printf("%d\n", Min);
	}
	return 0;
}