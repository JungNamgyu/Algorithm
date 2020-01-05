#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N, sum = 0;
	cin >> N;
	vector<int> c(N);
	for (int i = 0; i < N; i++)
		cin >> c[i];
	sort(c.begin(), c.end());
	for (int i = 0; i < N; i++)
		sum += c[i] * (N - i);
	cout << sum;
	return 0;
}