#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c, d, p, X, Y;
	cin >> a >> b >> c >> d >> p;
	X = a * p;
	Y = b + ((p > c) ? (p - c)*d : 0);
	cout << min(X, Y);
	return 0;
}