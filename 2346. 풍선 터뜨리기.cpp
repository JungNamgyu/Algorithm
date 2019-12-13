#include <iostream>
using namespace std;

int n, b[1001], ans[1001];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];

	int bc, inx, len = 0;

	ans[len++] = inx = 1;
	while (len < n) {
		bc = b[inx];
		b[inx] = 0;
		while (bc) {
			if (bc > 0) {
				inx++;
				if (inx > n) inx = 1;
				if (b[inx] != 0) bc--;
			}
			if (bc < 0) {
				inx--;
				if (inx < 1) inx = n;
				if (b[inx] != 0) bc++;
			}
		}
		ans[len++] = inx;
	}
	for (int i = 0; i < n; i++) 	cout << ans[i] << " ";
	return 0;
}