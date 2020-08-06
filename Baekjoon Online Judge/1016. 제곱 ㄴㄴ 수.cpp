#include<iostream>
#include<vector>
using namespace std;

vector <int> P;
bool S[1000001];
long long Min, Max;

int setPrime() {
	int i, j;
	bool p[1001001] = { false };
	for (i = 2; i <= 1001000; i++) {
		if (!p[i]) {
			P.push_back(i);
			for (j = i + i; j <= 1001000; j += i)
				p[j] = true;
		}
	}
	return P.size();
}

int main() {
	int size = setPrime();
	cin >> Min >> Max;
	for (int i = 0; i < size; i++) {
		long long s = 1LL * P[i] * P[i];
		if (Max < s)
			break;
		for (long long j = Min / s + (Min % s ? 1 : 0); j * s <= Max; j++)
			S[j * s - Min] = true;
	}
	int  No = 0;
	for (int i = 0; i <= Max - Min; i++) {
		if (!S[i]) No++;
	}
	cout << No;
	return 0;
}
