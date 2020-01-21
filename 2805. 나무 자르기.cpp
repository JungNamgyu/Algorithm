#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	vector <int> Tree(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Tree[i]);
	int ANS, le = 0, ri = 1e9;
	while (le <= ri) {
		long long sum = 0;
		int mid = (le + ri) / 2;
		for (int i = 0; i < N; i++)
			sum += (Tree[i] > mid ? Tree[i] - mid : 0);
		if (sum >= M) {
			ANS = mid;
			le = mid + 1;
		}
		else
			ri = mid - 1;
	}
	printf("%d", ANS);
	return 0;
}