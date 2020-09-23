#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int n1, int n2) {
	return (n1 % n2 == 0 ? n2 : gcd(n2, n1 % n2));
}

int main() {
	int d1, d2, n1, n2;
	cin >> d1 >> n1;
	cin >> d2 >> n2;
	
	int lcm = n1 * n2 / gcd(max(n1, n2), min(n1, n2));
	d1 *= (lcm / n1);
	d2 *= (lcm / n2);

	int d3 = d1 + d2, n3 = lcm;
	int GCD = gcd(max(d3, n3), min(d3, n3));
	cout << d3 / GCD << " " << n3 / GCD;
	return 0;
}