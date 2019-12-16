#include<iostream>
#include<algorithm>
#include<cctype>
#include<string>
using namespace std;

int main() {
	string s;
	int a[26] = { 0 }, Max = 0, t = 1;
	while (getline(cin, s)) {
		int len = s.length();
		for (int i = 0; i < len; i++)
			if (isalpha(s[i]))
				a[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		Max = max(Max, a[i]);
	for (int i = 0; i < 26; i++)
		if (Max == a[i]) cout << (char)(i + 'a');
	return 0;
}