#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct {
	char m[3][3][5000] = {  {"0","1","0"},
							{"0","0","1"},
							{"0","1","1"} };
}Z;
Z multi, matrix;

void sum(char a[],char b[]){
	reverse(a, a + strlen(a)), reverse(b, b + strlen(b));
	if (strlen(a) < strlen(b)) {
		char c[5000];
		strcpy(c, a); strcpy(a, b); strcpy(b, c);
	}
	int len_a = strlen(a);
	int len_b = strlen(b);
	for (int i = 0; i < len_a; i++)
		a[i] = ((len_b<=i) ? (a[i]-'0') : (a[i] - '0' + b[i] - '0'));
	for (int i = 0; i < len_a; i++) {
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	if (a[len_a]) len_a++;
	for (int i = 0; i < len_a; i++) a[i] += '0';
	reverse(a, a + len_a);
}

void mul(char s[], char Za[], char Zb[]) {
	char a[5000], b[5000], c[5000] = { 0 };
	strcpy(a, Za), strcpy(b, Zb);
	reverse(a, a + strlen(a)), reverse(b, b + strlen(b));
	if (strlen(a) < strlen(b)) {
		char d[5000];
		strcpy(d, a); strcpy(a, b); strcpy(b, d);
	}
	int len_a = strlen(a), len_b = strlen(b);
	for (int i = 0; i < len_b; i++) {
		for (int j = 0; j < len_a; j++) {
			c[i + j] += (a[j] - '0') * (b[i] - '0');
			c[i + j + 1] += c[i + j] / 10;
			c[i + j] %= 10;
		}
	}
	int len_c = len_a + len_b;
	for (len_c; !c[len_c - 1]; len_c--);
	for(int i=0;i<len_c;i++) c[i] += '0';
	reverse(c, c + len_c);
	if(len_c) sum(s, c);
}

void M_mul(Z a, Z b) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			strcpy(multi.m[y][x], "0");
			for (int i = 0; i < 3; i++) {
				mul(multi.m[y][x], a.m[y][i], b.m[i][x]);
			}
		}
	}
}

void Fibo(int n) {
	if (n > 1) {
		Fibo(n / 2);
		M_mul(multi, multi);
		if (n % 2)
			M_mul(multi, matrix);
	}
}

int main()
{
	int n;
	char ans[5000] = { "0" }, f[3][2] = { "0","1","1" };
	cin >> n;
	if (n > 0) {
		Fibo(n);
		for (int i = 0; i < 3; i++)
			mul(ans, multi.m[0][i], f[i]);
	}
	cout << (n ? ans : "0");
	return 0;
}