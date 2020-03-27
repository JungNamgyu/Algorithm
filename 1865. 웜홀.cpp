#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		int N, M, W;
		scanf("%d%d%d", &N, &M, &W);
		vector<int> Cost(N + 1, 1e9);
		vector< vector<int> > Next(N + 1);
		for (int i = 0; i < M + W; i++) {
			int S, E, T;
			scanf("%d%d%d", &S, &E, &T);
			if (i < M) {
				Next[S].push_back(E); Next[S].push_back(T);
				Next[E].push_back(S); Next[E].push_back(T);
			}
			else {
				Next[S].push_back(E); Next[S].push_back(-T);
			}
		}
		Cost[1] = 0;
		bool check = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int sz = Next[j].size();
				for (int k = 0; k < sz; k += 2) {
					if (Cost[Next[j][k]] > Cost[j] + Next[j][k + 1]) {
						Cost[Next[j][k]] = Cost[j] + Next[j][k + 1];
						if (i == N)
							check = true;
					}
				}
			}
		}
		printf("%s\n", (check ? "YES" : "NO"));
	}
	return 0;
}
