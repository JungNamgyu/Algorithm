﻿#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << m * 2 - n << " " << n - m << endl;
	}
	return 0;
}