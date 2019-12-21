#include<iostream>
using namespace std;

int n, sum, p[100][100];

int main() {
	cin >> n;
	while (n--) {
		int y, x;
		cin >> y >> x;
		for (int i = y; i < y + 10; i++)
			for (int j = x; j < x + 10; j++) p[i][j] = 1;
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++) sum += p[i][j];
	cout << sum;
	return 0;
}