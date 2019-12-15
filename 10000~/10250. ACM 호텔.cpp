#include<cstdio>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int h, w, n;
		scanf("%d%d%d", &h, &w, &n);
		int y = (n%h) * 100, x = (n / h) + 1;
		if (y == 0) y = h * 100, x -= 1;
		printf("%d\n", y + x);
	}
	return 0;
}