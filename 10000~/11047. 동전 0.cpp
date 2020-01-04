#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, K, cnt = 0;
	cin >> N >> K;
	vector <int> V(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> V[i];
	for (int i = N; i > 0 && K; i--) {
		cnt += K / V[i];
		K = K - (K / V[i])*V[i];
	}
	cout << cnt;
	return 0;
}