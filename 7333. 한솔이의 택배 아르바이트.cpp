// 7333. 한솔이의 택배 아르바이트

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int N, W[101], move = 0;
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> W[j];
		sort(W, W + N);
		int cnt = 1, le = 0, ri = N - 1;
		while (le <= ri) {
			if (W[ri]*cnt < 50)
				le++, cnt++;
			else
				ri--, move++, cnt = 1;
		}
		cout << "#" << i << " " << move << "\n";
	}
	return 0;
}