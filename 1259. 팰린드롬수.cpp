#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	while (true) {
		string s;
		cin >> s;
		if (!s.compare("0"))
			break;
		else {
			string x = s;
			reverse(x.begin(), x.end());
			cout << (s.compare(x) ?  "no" : "yes") << endl;
		}
	}
	return 0;
}