// 2072. 홀수만 더하기
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			int odd_check;
			cin >> odd_check;
			if (odd_check % 2) sum += odd_check;
		}
		cout << "#" << i << " " << sum << "\n";
	}
	return 0;
}