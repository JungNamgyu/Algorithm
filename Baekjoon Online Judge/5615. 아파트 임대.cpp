#include<iostream>
using namespace std;
using ull = unsigned long long;

ull modulo(ull a, ull d, ull n) {
	if (d == 1)
		return a;
	else {
		ull m = modulo(a, d / 2, n);
		return (((m * m) % n) * (d % 2 ? a : 1)) % n;
	}
}

bool miuller_rabin(ull n, ull a) {
	ull d = n - 1;
	for (; d % 2 == 0; d /= 2) {
		if (modulo(a, d, n) == n - 1)
			return true;
	}
	ull tmp = modulo(a, d, n);
	return (tmp == 1 || tmp == n - 1);
}

bool is_prime(ull n) {
	for (auto a : { 2, 3, 5, 7, 11 })
		if (!miuller_rabin(n, a))
			return false;
	return true;
}

int main() {
	int N, ans = 0;
	cin >> N;
	while (N--) {
		ull s;
		cin >> s;
		if (is_prime(2 * s + 1))
			ans = ans + 1;
	}
	cout << ans;
	return 0;
}
