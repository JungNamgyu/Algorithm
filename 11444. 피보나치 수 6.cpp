// 11444. 피보나치 수 6
#pragma warning(disable : 4996)

#include<stdio.h>
#define M 1000000007

typedef struct {
	long long m[3][3] = { {0,1,0},
					{0,0,1},
					{0,1,1} };
}Z;
Z multi, matrix;

void M_mul(Z a, Z b) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			multi.m[y][x] = a.m[y][0] * b.m[0][x];
			for (int i = 1; i < 3; i++) {
				multi.m[y][x] += a.m[y][i] * b.m[i][x];
			}
			multi.m[y][x] %= M;
		}
	}
}

void Fibo(long long n) {
	if (n > 1) {
		Fibo(n / 2);
		M_mul(multi, multi);
		if (n % 2)
			M_mul(multi, matrix);
	}
}

int main()
{
	int f[3] = { 0,1,1 };
	long long n, ans = 0;
	
	scanf("%lld", &n);
	if (n > 0) {
		Fibo(n);
		for (int i = 0; i < 3; i++)
			ans += multi.m[0][i] * f[i];
	}
	printf("%lld", ans % M);

	return 0;
}