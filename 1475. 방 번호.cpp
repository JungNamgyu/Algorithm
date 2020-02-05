#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string N;
	int cnt[10] = { 0 };
	cin >> N;
	for (int i = 0; i < N.length(); i++) {
		if (N[i] == '6' || N[i] == '9')
			(cnt[6] <= cnt[9] ? cnt[6] += 1 : cnt[9] += 1);
		else
			cnt[N[i] - '0']++;
	}
	int Max = 0;
	for (int i = 0; i <= 9; i++)
		Max = max(Max, cnt[i]);
	cout << Max;
	return 0;
}