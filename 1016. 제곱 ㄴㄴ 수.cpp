#include<iostream>
using namespace std;

bool ans[1000001];
long long Min, Max;
int prime[100000], cnt;

void setPrime() {
	int i, j;
	bool p[1001001] = { false };
	for (i = 2; i <= 1001000; i++) {
		if (!p[i]) {
			prime[cnt++] = i;
			for (j = i + i; j <= 1001000; j += i)
				p[j] = true;
		}
	}
}

int main() {
	setPrime();
	cin >> Min >> Max;
	for (int i = 0; i < cnt; i++) {
		long long inx, square = (long long)prime[i] * prime[i];
		if (Max < square)
			break;
		inx = Min / square;
		if (Min%square) inx++;
		for (; inx <= Max / square; inx++)
			ans[(inx*square) - Min] = true;
	}
	int  No = 0;
	for (int i = 0; i <= Max - Min; i++) {
		if (!ans[i]) No++;
	}
	cout << No;
	return 0;
}