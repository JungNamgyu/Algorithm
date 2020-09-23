#include<iostream>
#include<cmath>
using namespace std;

bool prime[250000];

int main() {
	prime[1] = true;
	for (int i = 2; i <= sqrt(123456 * 2); i++)
		if (!prime[i])
			for (int j = i + i; j <= 123456 * 2; j += i) prime[j] = true;
	while (true) {
		int n, cnt = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = n + 1; i <= 2 * n; i++)
			if (!prime[i]) cnt++;
		cout << cnt << endl;
	}
	return 0;
}