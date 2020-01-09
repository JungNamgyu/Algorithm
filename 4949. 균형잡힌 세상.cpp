#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	while (true) {
		string s;
		stack <char> S;
		getline(cin, s);
		if (s.size() == 1)
			break;
		bool check = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[')
				S.push(s[i]);
			else if (s[i] == ')' || s[i] == ']') {
				if (!S.empty()) {
					if (S.top() == '(' && s[i] == ')')
						S.pop();
					else if (S.top() == '[' && s[i] == ']')
						S.pop();
					else {
						check = false;
						break;
					}
				}
				else {
					check = false;
					break;
				}					
			}
		}
		if (!S.empty())
			check = false;
		cout << (check ? "yes\n" : "no\n");
	}
	return 0;
}