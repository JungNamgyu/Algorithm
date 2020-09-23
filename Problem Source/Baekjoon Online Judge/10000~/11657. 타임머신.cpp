#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	vector < int > Cost(N + 1, 1e9);
	vector < vector < pair<int, int> > > Edge(N + 1);
	
	for (int i = 0; i < M; i++) {
		int a; pair<int, int> b;
		scanf("%d%d%d", &a, &b.first, &b.second);
		Edge[a].push_back(b);
	}
	Cost[1] = 0;
	bool check = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Cost[j] != 1e9) {
				int sz = Edge[j].size();
				for (int k = 0; k < sz; k++) {
					int next = Edge[j][k].first, cost = Edge[j][k].second;
					if (Cost[next] > Cost[j] + cost) {
						Cost[next] = Cost[j] + cost;
						if (i == N)
							check = true;
					}
				}
			}
		}
	}
	if (check)
		printf("-1\n");
	else
		for (int i = 2; i <= N; i++)
			printf("%d\n", (Cost[i] == 1e9 ? -1 : Cost[i]));
	return 0;
}