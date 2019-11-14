// 2071. 평균값 구하기
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			int value;
			cin >> value;
			sum += value;
		}
		sum += 5; //반올림
		cout << "#" << i << " " << (int)(sum / 10.0) << "\n";
	}
	return 0;
}