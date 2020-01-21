#include<iostream>
using namespace std;
#define M 1000000007

long long Fact(int x) {
	long long ANS = 1;
	for (int i = 1; i <= x; i++)
		ANS = (ANS * i) % M;
	return ANS;
}

long long Div_Con(int n, int p) {
	if (p == 1)
		return n;
	else {
		long long div_con = Div_Con(n, p / 2);
		div_con = (((div_con * div_con) % M) * (p % 2 ? n : 1)) % M;
		return div_con;
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	long long A = Fact(N);
	long long B = Div_Con((Fact(K) * Fact(N - K)) % M, M - 2);
	cout << (A * B) % M;
	return 0;
}