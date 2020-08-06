#include <iostream>
#include <algorithm>
using namespace std;

int n, a, b, c, D[2][200000], Max;

int main()
{
	cin >> n;
	cin >> a >> b;

	D[0][0] = 1;
	D[0][1] = 1; D[1][1] = 0;
	if (a < b)
		D[0][1]++;
	Max = D[0][1];

	for (int i = 2; i < n; i++) {
		cin >> c;
		D[0][i] = 1, D[1][i] = 0;
		if (a < c) D[1][i] += D[0][i - 2] + 1;
		if (b < c) {
			D[0][i] = D[0][i - 1] + 1;
			D[1][i] = max(D[1][i], D[1][i - 1] + 1);
		}
		a = b, b = c;
		Max = max(max(Max, D[0][i]), D[1][i]);
	}
	cout << Max;
	return 0;
}
