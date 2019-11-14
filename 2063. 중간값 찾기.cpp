// 2063. 중간값 찾기

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int data[200];
	for (int i = 0; i < N; i++)
		cin >> data[i];
	sort(data, data + N);
	cout << data[N / 2];

	return 0;
}