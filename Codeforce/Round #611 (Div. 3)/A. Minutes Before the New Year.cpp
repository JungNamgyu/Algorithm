#include<iostream>
using namespace std;

int main() {
	int t, h = 23, m = 60;
	cin >> t;
	while (t--) {
		int H, M;
		cin >> H >> M;
		cout << (h - H) * 60 + m - M << endl;
	}
	return 0;
}
