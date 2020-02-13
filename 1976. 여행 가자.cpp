#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> p;

int Union(int a, int b) {
	if (p[a] == a && p[b] == b)
		return p[a] = p[b] = min(p[a], p[b]);
	else
		return p[a] = p[b] = Union(p[a], p[b]);
}

int Find(int x) {
	if (p[x] == x)
		return x;
	else
		return p[x] = Find(p[x]);
}

int main() {
	int n, m;

	cin >> n >> m;
	p.resize(n + 1);
	for (int i = 0; i <= n; i++) p[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int path;
			cin >> path;
			if (path == 1) Union(i, j);
		}
	}

	int st, en;
	bool check = true;
	cin >> st;
	for (int i = 1; i < m; i++) {
		cin >> en;
		Find(st); Find(en);
		if (p[st] != p[en])
			check = false;
		st = en;
	}
	cout << (check ? "YES" : "NO") << endl;

	return 0;
}