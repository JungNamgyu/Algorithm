#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n;
string s[200001];

bool cmp_l(string a, string b) {
	return (a.length() < b.length()) ? 1 : 0;
}

int main() {
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++) 	cin >> s[i];
	sort(s, s + n, cmp_l);
	for (i = 0; i < n; i = j) {
		for (j = i + 1; s[j].length() == s[i].length(); j++);
		sort(s + i, s + j);
	}
	cout << s[0] << endl;
	for (int i = 1; i < n; i++)
		if (s[i - 1].compare(s[i])) cout << s[i] << endl;
	return 0;
}