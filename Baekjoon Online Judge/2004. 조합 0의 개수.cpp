#include<iostream>
using namespace std;

typedef struct Z {
	long long s2 = 0;
	long long s5 = 0;
}S;

S count(int x) {
	S cn;
	for (long long i = 2; i <= x; i*=2)
		cn.s2 += x / i;
	for (long long i = 5; i <= x; i*=5)
		cn.s5 += x / i;
	return cn;
}

int main() {
	int n, m;
	cin >> n >> m;

	S a = count(n);
	S b = count(m), c = count(n-m);
	
	a.s2 = a.s2 - b.s2 - c.s2;
	a.s5 = a.s5 - b.s5 - c.s5;

	cout << (a.s2 > a.s5 ? a.s5 : a.s2);

	return 0;
}