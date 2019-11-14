// 2068. 최대수 구하기
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int max = 0;
		for (int j = 0; j < 10; j++) {
			int data;
			cin >> data;
			max = max > data ? max : data;
		}
		cout << "#" << i << " " << max << "\n";
	}
	return 0;
}