#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coin(n), D(k + 1);
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	D[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++)
			D[j] += D[j - coin[i]];
	}
	cout << D[k];
	return 0;
}