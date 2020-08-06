#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
using namespace std;

int N, R, Q;
vector < int > sz;
vector < bool > visit;
vector < vector<int> > e;

int make_tree(int x) {
	int i, edge_sz = e[x].size();
	visit[x] = true;
	for (i = 0; i < edge_sz; i++) {
		if (!visit[e[x][i]]) {
			sz[x] += make_tree(e[x][i]);
		}
	}
	return sz[x];
}

int main() {
	int i, j;
	scanf("%d%d%d", &N, &R, &Q);
	e.resize(N + 1);
	sz.resize(N + 1, 1);
	visit.resize(N + 1, false);
	for (i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	make_tree(R);

	for (i = 0; i < Q; i++) {
		int U;
		scanf("%d", &U);
		printf("%d\n", sz[U]);
	}
	return 0;
}