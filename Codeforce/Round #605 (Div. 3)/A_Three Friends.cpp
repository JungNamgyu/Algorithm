#include <iostream>
#include <algorithm>
using namespace std;

inline int abs(int x, int y) { return (x > y) ? (x - y) : (y - x); }

int main()
{
	int n;
	cin >> n;
	while (n--) {
		int a, b, c, Min = 2e9;
		cin >> a >> b >> c;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				for (int k = -1; k <= 1; k++) {
					Min = min(Min, abs(a + i, b + j) + abs(a + i, c + k) + abs(b + j, c + k));
				}
			}
		}
		cout << Min << endl;
	}
	return 0;
}
