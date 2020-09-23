#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	string s;
	long long sum = 0, len = 0;
	bool alpha[26] = { false };
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < k; i++) {
		char c; cin >> c;
		alpha[c - 'a'] = true;
	}
	for (int i = 0; i < n; i++) {
		if (alpha[s[i] - 'a']) len++;
		else {
			sum += (len*(len + 1)) / 2;
			len = 0;
		}
	}
	sum += (len*(len + 1)) / 2;
	len = 0;
	cout << sum;
	return 0;
}
