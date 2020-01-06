#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (a%b == 0)
		return b;
	return gcd(b, a%b);
}

int main() {
	int N, F;
	cin >> N >> F;
	for (int i = 1; i < N; i++) {
		int M;
		cin >> M;
		int GCD = (F > M ? gcd(F, M) : gcd(M, F));
		cout << F / GCD << "/" << M / GCD << endl;
	}
	return 0;
}