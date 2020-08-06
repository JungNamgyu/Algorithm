#include<cstdio>
#include<cmath>

int prime[1500];
bool p[10001] = { true, true };

int main() {
	int t, cnt = 0;

	for (int i = 2; i <= 10000; i++) {
		if (!p[i]) {
			prime[cnt++] = i;
			for (int j = i + i; j <= 10000; j += i) p[j] = true;
		}
	}

	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int le = 0, ri = cnt - 1, c1, c2;
		while(le<=ri){
			if (prime[le] + prime[ri] > n)
				ri--;
			else if (prime[le] + prime[ri] < n)
				le++;
			else {
				c1 = prime[le];
				c2 = prime[ri];
				le++, ri--;
			}
		}
		printf("%d %d\n", c1, c2);
	}
	return 0;
}