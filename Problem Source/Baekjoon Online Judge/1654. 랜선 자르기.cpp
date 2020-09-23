#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int K, N;
	scanf("%d%d", &K, &N);
	vector <int> Lan(K);
	for (int i = 0; i < K; i++)
		scanf("%d", &Lan[i]);
	long long ANS, le = 1, ri = (1 << 31) - 1;
	while (le <= ri) {
		long long sum = 0, mid = (le + ri) / 2;
		for (int i = 0; i < K; i++)
			sum += Lan[i] / mid;
		if (sum >= N) {
			ANS = mid;
			le = mid + 1;
		}
		else
			ri = mid - 1;
	}
	printf("%lld", ANS);
	return 0;
}