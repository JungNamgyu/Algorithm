#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p, k;
		cin >> n >> p >> k;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		int Max = 0;
		for (int i = 0, pre = 0; i < k && pre <= p; i++) {
			int cnt = i;
			for (int j = i + k - 1, sum = pre; j < n && sum + a[j] <= p; j += k) {
				cnt += k;
				sum += a[j];
			}
			pre += a[i];
			Max = max(Max, cnt);
		}
		cout << Max << endl;
	}
	return 0;
}
