#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int len;
		bool check = true;
		string ps; stack<char> s;
		cin >> ps;
		len = ps.length();
		for (int i = 0; i < len; i++) {
			if (ps[i] == '(') s.push(ps[i]);
			else {
				if (s.empty()) { check = false; break; }
				s.pop();
			}
		}
		cout << ((check && s.empty()) ? "YES\n" : "NO\n");
	}
	return 0;
}