#pragma warning(disable:4996)

#include<cstdio>
#include<algorithm>
using namespace std;

int GCD(int a, int b) {
	return ((a % b) ? GCD(b, a % b) : b);
}

int main() {
	int T;
	
	scanf("%d", &T);
	while (T--) {
		int n, d;

		scanf("%d %d", &n, &d);
		printf("%d\n", n / GCD(max(n, d), min(n, d)));
	}
	
	return 0;
}