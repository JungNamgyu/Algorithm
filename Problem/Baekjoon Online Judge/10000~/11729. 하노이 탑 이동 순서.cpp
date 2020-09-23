#include<cstdio>

void hanoi(int n, int s, int e) {
	if (n > 0) {
		hanoi(n - 1, s, 6 - s - e);
		printf("%d %d\n", s, e);
		hanoi(n - 1, 6 - s - e, e);
	}
}

int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << endl;
	hanoi(n, 1, 3);
	return 0;
}