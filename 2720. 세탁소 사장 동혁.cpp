#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		cout << c / 25 << " " << (c % 25) / 10 << " " << ((c % 25) % 10) / 5 << " " << (((c % 25) % 10) % 5) << endl;
	}
	return 0;
}