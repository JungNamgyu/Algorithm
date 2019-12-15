#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int n, x;
	string ps;
	stack<int> s;
	cin >> n;
	while (n--) {
		cin >> ps;
		if (!ps.compare("push")) {
			cin >> x; s.push(x);
		}
		if (!ps.compare("pop")) {
			cout << (s.empty() ? -1 : s.top()) << "\n";
			if (!s.empty()) s.pop();
		}
		if (!ps.compare("size")) cout << s.size() << "\n";
		if (!ps.compare("empty")) cout << (int)s.empty() << "\n";
		if (!ps.compare("top")) cout << (s.empty() ? -1 : s.top()) << "\n";
	}
	return 0;
}