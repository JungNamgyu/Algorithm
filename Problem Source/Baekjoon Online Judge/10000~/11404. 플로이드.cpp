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
		Cost[a][b] = min(Cost[a][b], c);
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					Cost[i][j] = 0;
				if (Cost[i][j] > Cost[i][k] + Cost[k][j])
					Cost[i][j] = Cost[i][k] + Cost[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", (Cost[i][j] == 1e7 ? 0 : Cost[i][j]));
		printf("\n");
	}
	return 0;
}