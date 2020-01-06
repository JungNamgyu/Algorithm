#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N, Min = 2e9;
	cin >> N;
	vector<int> P(N), ANS;
	for (int i = 0; i < N; i++)
		cin >> P[i];
	sort(P.begin(), P.end());
	for (int i = 1; i < N; i++)
		Min = min(Min, P[i] - P[i - 1]);
	for (int i = 1; i * i <= Min; i++) {
		if (Min % i == 0) {
			ANS.push_back(i);
			if(i != Min / i)
				ANS.push_back(Min / i);
		}
	}
	sort(ANS.begin(), ANS.end());
	for (int i = 1; i < (int)ANS.size(); i++) {
		bool ch = true;
		int m = P[0] % ANS[i];
		for (int j = 1; j < N; j++)
			if (P[j] % ANS[i] != m)
				ch = false;
		if(ch)	
			cout << ANS[i] << " ";
	}
	return 0;
}
