// 7964. 부먹왕국의 차원 관문
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int N, D;
		cin >> N >> D;

		int ANS = 0;
		for (int j = 0, cnt= 0; j < N; j++) {
			int data;
			cin >> data;
			if (data == 0) cnt++;
			if ((data == 1 || j == (N-1)))
				ANS += cnt / D, cnt = 0;
		}
		cout << '#' << i << ' ' << ANS << endl;
	}
	return 0;
}