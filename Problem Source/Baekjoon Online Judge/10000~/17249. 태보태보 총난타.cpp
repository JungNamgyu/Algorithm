#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool c = false;
	int len = s.length(), le = 0, ri = 0;
	for (int i = 0; i < len; i++) {
		if(s[i] == '@')
			c ? ri += 1 : le += 1;
		if (s[i] == '(') 
			c = true;
	}
	cout << le << " " << ri;
	return 0;
}