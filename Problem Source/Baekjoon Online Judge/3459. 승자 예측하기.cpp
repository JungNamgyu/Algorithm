// 3459. 승자 예측하기

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		long long N;
		cin >> N;
		long long win;
		int N_level = log(N) / log(2);
		if (N_level % 2) {
			for (int level = 1, win=2; level < N_level; level += 2)
				win = 4 * win + 2;
			cout << "#" << i << " " << ((win <= N) ? "Alice" : "Bob") << "\n";
		}
		else {
			for (int level = 0, win=1; level < N_level; level += 2)
				win = 4 * win+2;
			cout << "#" << i << " " << ((win <= N) ? "Bob" : "Alice") << "\n";
		}
	}

	return 0;
}