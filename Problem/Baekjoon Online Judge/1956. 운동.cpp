#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector < vector <int> > Cost(n + 1, vector<int>(n + 1, 1e7));

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		Cost[a][b] = c;
	}
	int Min = 2e9;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (Cost[i][j] > Cost[i][k] + Cost[k][j]) {
					if (i == j)
						Min = min(Min, Cost[i][k] + Cost[k][j]);
					Cost[i][j] = Cost[i][k] + Cost[k][j];
				}
			}
		}
	}

	printf("%d", (Min == 2e9 ? -1 : Min));
	return 0;
}