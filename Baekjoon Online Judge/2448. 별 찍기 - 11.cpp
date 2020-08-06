#include<cstdio>

bool star[3073][5121];

void s(int y, int x, int n) {
	if (n == 3) {
		star[y - 1][x] = true;
		star[y][x - 1] = star[y][x + 1] = true;
		star[y + 1][x - 2] = star[y + 1][x - 1] = star[y + 1][x] = star[y + 1][x + 1] = star[y + 1][x + 2] = true;
	}
	else {
		if (n == 6)
			s(y - (n / 4) - 1, x, n / 2);
		else
			s(y - (n / 4), x, n / 2);
		s(y + (n / 4), x - (n / 2), n / 2);
		s(y + (n / 4), x + (n / 2), n / 2);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	s(N / 2, N, N);
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N*2; j++)
			printf("%c", (star[i][j] ? '*' : ' '));
		printf("\n");
	}
	return 0;
}