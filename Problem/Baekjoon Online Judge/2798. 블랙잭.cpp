#include<iostream>
#include<algorithm>
using namespace std;

int n, m, Max, card[100];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> card[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = card[i] + card[j] + card[k];
				if (m >= sum) Max = max(Max, sum);
			}
		}
	}
	cout << Max;
	return 0;
}