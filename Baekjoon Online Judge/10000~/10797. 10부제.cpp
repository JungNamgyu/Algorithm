#include <iostream>
using namespace std;

int main()
{
	int d, n, cnt = 0;
	cin >> d;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		if (d == n) cnt++;
	}
	cout << cnt;
	return 0;
}