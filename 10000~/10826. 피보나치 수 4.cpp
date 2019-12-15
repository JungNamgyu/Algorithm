#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char fibo[10001][5000] = {"0","1"};

void sum(char s[], char a[],char b[]){
    if (strlen(a) < strlen(b)) {
	char c[5000];
	strcpy(c, a); strcpy(a, b); strcpy(b, c);
    }
    int len_a = strlen(a), len_b = strlen(b);
    reverse(a, a + len_a), reverse(b, b + len_b);
    for (int i = 0; i < len_a; i++)
	s[i] = ((len_b<=i) ? (a[i]-'0') : (a[i] - '0' + b[i] - '0'));
    for (int i = 0; i < len_a; i++) {
	s[i + 1] += s[i] / 10;
	s[i] %= 10;
    }
    int len_s = len_a;
    if (s[len_s]) len_s++;
    for (int i = 0; i < len_s; i++) s[i] += '0';
    reverse(a, a + len_a), reverse(s, s + len_s);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
        sum(fibo[i], fibo[i-1], fibo[i-2]);
    cout << fibo[n];
    return 0;
}
