#pragma warning (disable:4996);

#include<cstdio>

int M, N, arr[10];

void Sequence(int inx) {
	if (inx == N) {
		for (int i = 0; i < inx; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= M; i++) {
			arr[inx] = i;
			Sequence(inx + 1);
		}
	}
}

int main() {
	scanf("%d%d", &M, &N);
	Sequence(0);
	return 0;
}