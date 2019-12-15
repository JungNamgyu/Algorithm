#include<cstdio>

int main() {
	int n, m, d[10001] = { 0 };
	scanf("%d", &n);
	while (n--) { scanf("%d", &m); d[m]++; }
	for (int i = 1; i < 10001; i++) { while(d[i]--) cout << i << "\n"; }
	return 0;
}