#include<iostream>
using namespace std;
inline long long POW(int x) { return 1L * x * x; }

int Multi(int A, int B, int C) {
	if (B == 1)
		return A % C;
	else
		return ((POW(Multi(A, B / 2, C)) % C) *(B % 2 ? A : 1)) % C;
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << Multi(A, B, C);
	return 0;
}