#pragma warning (disable:4996)

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int V, E, K;
	scanf("%d%d%d", &V, &E, &K);
	
	vector <int> dis(V + 1, 2e9);
	vector < vector<int> > list(V + 1);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		list[u].push_back(v), list[u].push_back(w);
	}

	priority_queue < pair<int, int> > Min_heap;
	dis[K] = 0;
	Min_heap.push({ dis[K], K });
	while (!Min_heap.empty()) {
		pair<int, int> x = Min_heap.top();
		Min_heap.pop();
		for (int i = 0; i < list[x.second].size(); i += 2) {
			if ((-x.first + list[x.second][i + 1]) < dis[list[x.second][i]]) {
				dis[list[x.second][i]] = (-x.first + list[x.second][i + 1]);
				Min_heap.push({ -(-x.first + list[x.second][i + 1]), list[x.second][i] });
			}
		}
	}
	for (int i = 1; i <= V; i++)
		dis[i] == 2e9 ? printf("INF\n") : printf("%d\n", dis[i]);
	return 0;
}