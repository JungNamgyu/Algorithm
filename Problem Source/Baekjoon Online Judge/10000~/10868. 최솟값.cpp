#pragma warning(disable:4996)

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	int st = 1 << (int)ceil(log2(N));
	vector <int> tree(st << 1, 2e9);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[st + i]);
		for (int x = (st + i); x >= 1; x /= 2)
			tree[x / 2] = min(tree[x / 2], tree[x]);
	}

	for (int i = 0, a, b; i < M; i++){
		scanf("%d %d", &a, &b);

		int Min = 2e9;
		for (int le = st + a - 1, ri = st + b - 1; le <= ri; le /= 2, ri /= 2) {
			if (le % 2 == 1)
				Min = min(Min, tree[le]), le++;
			if (ri % 2 == 0)
				Min = min(Min, tree[ri]), ri--;
		}
		printf("%d\n", Min);
	}
	return 0;
}