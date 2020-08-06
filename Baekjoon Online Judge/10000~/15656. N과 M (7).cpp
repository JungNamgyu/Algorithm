#pragma warning(disable:4996)

#include<cstdio>
#include<algorithm>
using namespace std;

int N, M, S[10], P[10];

void DFS(int inx) {
	if (inx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", P[i]);
		printf("\n");
	}
	else {
		for (int i = 0; i < N; i++) {
			P[inx] = S[i];
			DFS(inx + 1);
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &S[i]);
	sort(S, S + N);
	DFS(0);
	return 0;
}