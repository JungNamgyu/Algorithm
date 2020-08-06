#include<iostream>
#include<string>
using namespace std;

inline int abs(int x) { return (x > 0 ? x : -x); }

int check(int a[], int b[], int sz) {
	int cnt = 0;
	bool check = false;
	for (int i = 0; i < 26; i++) {
		cnt += abs(a[i] - b[i]);
		if (cnt > sz)
			return 0;
	}
	return 1;
}

int main() {
	string word;
	int n, cnt = 0, W[26] = { 0 };

	cin >> n >> word;
	for (int i = 0; i < word.length(); i++) W[word[i] - 'A']++;

	for (int i = 1; i < n; i++) {
		string s;
		int S[26] = { 0 };

		cin >> s;
		for (int i = 0; i < s.length(); i++) S[s[i] - 'A']++;

		if(word.length() == s.length())
			cnt += check(W, S, 2);
		else
			cnt += check(W, S, 1);
	}
	cout << cnt;
	return 0;
}