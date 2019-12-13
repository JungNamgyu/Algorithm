#include <iostream>
#include <algorithm>
using namespace std;

int n, D[1000001];

int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1);
		if (i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1);
	}
	cout << D[n];
	return 0;
}