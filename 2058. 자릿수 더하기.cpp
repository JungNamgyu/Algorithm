// 2058. 자릿수 더하기

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int sum = 0;
	while (N) {
		sum += (N % 10);
		N /= 10;
	}
	cout << sum;
}