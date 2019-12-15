#include<cstdio>

int main() {
	int t, D[15][15] = { {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 } };
	for (int k = 1; k <= 14; k++) {
		for (int n = 1; n <= 14; n++) {
			for (int d = 1; d <= n; d++) D[k][n] += D[k - 1][d];
		}
	}
	scanf("%d", &t);
	while (t--) {
		int k, n;
		scanf("%d%d", &k, &n);
		printf("%d\n", D[k][n]);
	}
	return 0;
}