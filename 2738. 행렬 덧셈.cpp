#include<cstdio>

int n, m, arr1[100][100], arr2[100][100];

int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &arr1[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &arr2[i][j]);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", arr1[i][j] + arr2[i][j]);
		printf("\n");
	}
	return 0;
}