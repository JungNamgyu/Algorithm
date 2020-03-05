#include<iostream>
using namespace std;

int N, r, c, cnt = 0;

void func(int N, int y, int x) {
	if (N == 1) {
		if (y == r && x == c) cout << cnt;
	}
	else {
		if (y <= r && r < y + (N / 2) && x <= c && c < x + (N / 2))
			func(N / 2, y, x);
		else
			cnt += (N / 2) * (N / 2);

		if (y <= r && r < y + (N / 2) && x + (N / 2) <= c && c < x + N)
			func(N / 2, y, x + (N / 2));
		else
			cnt += (N / 2) * (N / 2);
		
		if (y + (N / 2) <= r && r < y + N && x <= c && c < x + (N / 2))
			func(N / 2, y + (N / 2), x);
		else
			cnt += (N / 2) * (N / 2);
		
		func(N / 2, y + (N / 2), x + (N / 2));
	}
}

int main() {
	cin >> N >> r >> c;
	func((1<<N), 0, 0);
	return 0;
}