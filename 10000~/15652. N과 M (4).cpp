#pragma warning (disable:4996);

#include<cstdio>

int M, N, arr[10];

void Sequence(int inx, int st) {
	if (inx == N) {
		for (int i = 0; i < inx; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else {
		for (int i = st; i <= M; i++) {
			arr[inx] = i;
			Sequence(inx + 1, i);
		}
	}
}

int main() {
	scanf("%d%d", &M, &N);
	Sequence(0, 1);
	return 0;
}