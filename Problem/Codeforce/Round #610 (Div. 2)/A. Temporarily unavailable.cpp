#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, r, sum = 0;
		cin >> a >> b >> c >> r;
		if (a > b) { int t = a; a = b; b = t; }
		int rc = c - r, cr = c + r;
		if (a <= rc && cr <= b)
			sum = rc - a + b - cr;
		else if (a <= rc && rc <= b && b < cr)
			sum = rc - a;
		else if (rc < a && a <= cr && cr <= b)
			sum = b - cr;
		else if (rc < a && b < cr)
			sum = 0;
		else
			sum = b - a;
		cout << sum << endl;
	}
	return 0;
}
