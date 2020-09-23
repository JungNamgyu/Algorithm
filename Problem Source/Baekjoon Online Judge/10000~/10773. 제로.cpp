#include<iostream>
#include<stack>
using namespace std;

int main() {
	int K;
	stack <int> S;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int N;
		cin >> N;
		if (N == 0)
			S.pop();
		else
			S.push(N);
	}
	int sum = 0;
	while (!S.empty()) {
		sum += S.top();
		S.pop();
	}
	cout << sum;
	return 0;
}