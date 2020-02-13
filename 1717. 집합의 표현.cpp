#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> p;

int Union(int a, int b) {
	if (p[a] == a && p[b] == b)
		return p[a] = p[b] = min(p[a], p[b]);
	else {
		return p[a] = p[b] = Union(p[a], p[b]);
	}
}

int Find(int x) {
	if (p[x] == x)
		return x;
	else
		return p[x] = Find(p[x]);
}

int main() {
	int n, m;
	
	scanf("%d%d", &n, &m);
	p.resize(n + 1);
	for (int i = 0; i <= n; i++) p[i] = i;

	while (m--) {
		int c, a, b;
		scanf("%d%d%d", &c, &a, &b);
		if (c == 0)
			Union(a, b);
		else {
			Find(a); Find(b);
			printf("%s\n", (p[a] == p[b] ? "YES" : "NO"));
		}
	}

	return 0;
}