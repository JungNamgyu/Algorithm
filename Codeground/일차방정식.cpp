#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int GCD(int a, int b) {
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int a, b, c;

		scanf("%dx - %d = %d", &a, &b, &c);

		int gcd = GCD(max(a, b + c), min(a, b + c));
		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << "Case #" << test_case + 1 << endl;
		cout << (b + c) / gcd << " / " << a / gcd << endl;
	}

	return 0;
}