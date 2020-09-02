#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Z {
	int v, dis;
	bool operator> (Z other) {
		return dis > other.dis;
	}
};

int main() {
	int N, M, K, X;

	cin >> N >> M >> K >> X;

	vector< int > dis(N + 1, 2e9);
	vector< vector<int> > edge(N + 1);
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		edge[A].push_back(B);
	}
	
	priority_queue < Z, vector<Z>, greater<> > pq;

	dis[X] = 0;
	pq.push(Z{ X, 0 });
	for (int i = 0; i < N; i++) {
		Z now = pq.top(); pq.pop();
		
		for (auto& next : edge[now.v]) {
			if (now.dis + 1 < dis[next]) {
				dis[next] = now.dis + 1;
				pq.push(Z{ next, now.dis + 1 });
			}
		}
	}

	vector < int > ans;
	for (int i = 1; i <= N; i++) {
		if (dis[i] == K)
			ans.push_back(i);
	}
	
	if (ans.size() == 0)
		cout << -1 << '\n';
	else {
		for (auto i : ans)
			cout << i << '\n';
	}
	return 0;
}