#include<string>
#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int  len = s.length();
	for (int i = 0; i < len; i++) {
		if (islower(s[i]))
			s[i] = toupper(s[i]);
		else
			s[i] = tolower(s[i]);
	}
	cout << s;
	return 0;
}