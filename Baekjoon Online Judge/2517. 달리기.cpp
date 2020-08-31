#pragma warning(disable:4996)

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

struct Z {
	int a, inx;
	bool operator<(Z other) {
		return a < other.a;
	}
};

int main() {
	int n;

	scanf("%d", &n);
	vector <Z> A(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &A[i].a), A[i].inx = i;
	sort(A.begin(), A.end());

	int st = 1 << (int)ceil(log2(n));
	vector <int> tree(st << 1), ch(st << 1);
	for (int i = 0; i < n; i++) ch[A[i].inx] = i;

	for (int i = 0, ans = 1; i < n; ans = 1, i++) {
		for (int x = st + ch[i]; x >= 1; x /= 2)
			tree[x]++;
		for (int le = st + ch[i] + 1, ri = st + n - 1; le <= ri; le /= 2, ri /= 2) {
			if (le % 2 == 1)
				ans += tree[le], le++;
			if (ri % 2 == 0)
				ans += tree[ri], ri--;
		}
		printf("%d\n", ans);
	}
	return 0;
}