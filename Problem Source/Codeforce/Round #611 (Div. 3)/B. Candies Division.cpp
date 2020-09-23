#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long int n, k;
		scanf("%lld%lld", &n, &k);
		if ((float)n / k == n / k)
			printf("%lld\n", n);
		else 
			printf("%lld\n", ((n / k) * k) + min(n%k, k/2));
	}
	return 0;
}
