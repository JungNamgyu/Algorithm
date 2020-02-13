#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector < vector<int> > Cache, Dist;

int TSP(int cur, int visited) {
	if (visited == (1 << N) - 1) return Dist[cur][0];

	int& ret = Cache[cur][visited];
	if (ret != 0) return ret;
	ret = 2e9;
	for (int next = 0; next < N; next++) {
		if (Dist[cur][next] == 0) continue;
		if (visited & (1 << next)) continue;
		ret = min(ret, TSP(next, visited | (1 << next)) + Dist[cur][next]);
	}
	
	return ret;
}

int main() {
	cin >> N;
	Dist.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Dist[i][j];
	Cache.resize(N, vector<int>(1 << N));

	cout << TSP(0, 1);
	return 0;
}