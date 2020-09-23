#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main() {
	int N;
	cin >> N;
	vector<int> P(N), ANS;
	for (int i = 0; i < N; i++)
		cin >> P[i];
	sort(P.begin(), P.end());
	int GCD = P[1] - P[0];
	for (int i = 2; i < N; i++)
		GCD = (GCD > P[i] - P[i - 1] ? gcd(GCD, P[i] - P[i - 1]) : gcd(P[i] - P[i - 1], GCD));
	for (int i = 1; i * i <= GCD; i++) {
		if (GCD % i == 0) {
			ANS.push_back(i);
			if (i != GCD / i)
				ANS.push_back(GCD / i);
		}
	}
	sort(ANS.begin(), ANS.end());
	for (int i = 1; i < (int)ANS.size(); i++)
		cout << ANS[i] << " ";
	return 0;
}
