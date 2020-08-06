#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int GCD(int a, int b) {
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int main() {
	int n, gcd;
	cin >> n;
	vector<int> ans;
	if (n == 2) {
		int a, b;
		cin >> a >> b;
		gcd = (b > a ? GCD(b, a) : GCD(a, b));
	}
	else if (n == 3) {
		int a, b, c;
		cin >> a >> b >> c;
		gcd = (b > a ? GCD(b, a) : GCD(a, b));
		gcd = (c > gcd ? GCD(c, gcd) : GCD(gcd, c));
	}
	for (int i = 1; i * i <= gcd; i++) {
		if (i * i == gcd)
			ans.push_back(i);
		else if (gcd % i == 0) {
			ans.push_back(i);
			ans.push_back(gcd / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}