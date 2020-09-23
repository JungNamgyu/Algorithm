#include<cstdio>

bool star[6561][6561];

void s(int n, int i, int j) {
	if (n == 1)
		star[i][j] = true;
	else {
		s(n / 3, i - (n / 3), j - (n / 3)), s(n / 3, i - (n / 3), j), s(n / 3, i - (n / 3), j + (n / 3));
		s(n / 3, i,           j - (n / 3)),                           s(n / 3, i,           j + (n / 3));
		s(n / 3, i + (n / 3), j - (n / 3)), s(n / 3, i + (n / 3), j), s(n / 3, i + (n / 3), j + (n / 3));
	}
}

int main() {
	int n;
	scanf("%d", &n);
	s(n, n / 2, n / 2);
	for (int i = 0; i < n; i++) {
		for(int j=0;j<n;j++)
			printf("%c", (star[i][j] ? "*" : " "));
		printf("\n");
	}
	return 0;
}