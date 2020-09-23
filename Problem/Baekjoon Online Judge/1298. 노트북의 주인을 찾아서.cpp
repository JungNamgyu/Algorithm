#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<bool>& visit, vector<int>& b, vector< vector<int> >& edge, int now) {
	if (visit[now])
		return false;

	visit[now] = true;
	for (int next : edge[now]) {
		if (b[next] == 0 || dfs(visit, b, edge, b[next])) {
			b[next] = now;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M;

	cin >> N >> M;
	vector< vector<int> > edge(N + 1);

	for(int i = 0, a, b; i< M;i++){
		cin >> a >> b;
		edge[a].push_back(b);
	}

	int ans = 0;
	vector<int> b(N + 1, 0);
	vector<bool> visit(N + 1);

	for (int i = 1; i <= N; i++) {
		fill(visit.begin(), visit.end(), 0);

		if (dfs(visit, b, edge, i)) 
			ans++;
	}
	cout << ans << '\n';

	return 0;
}