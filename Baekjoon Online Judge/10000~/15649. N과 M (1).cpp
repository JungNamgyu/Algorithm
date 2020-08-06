#include<cstdio>

bool ch[10];
int M, N, arr[10];

void Sequence(int inx) {
	if (inx == N) {
		for (int i = 0; i < inx; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= M; i++) {
			if (!ch[i]) {
				ch[i] = true;
				arr[inx] = i;
				Sequence(inx + 1);
				ch[i] = false;
			}
		}
	}
}

int main() {
	scanf("%d%d", &M, &N);
	Sequence(0);
	return 0;
}