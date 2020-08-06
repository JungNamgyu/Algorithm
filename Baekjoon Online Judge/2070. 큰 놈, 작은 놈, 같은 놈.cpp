// 2070. 큰 놈, 작은 놈, 같은 놈

#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int a, b;
		cin >> a >> b;

		cout << "#" << i << " ";
		if (a == b)
			cout << "=";
		else
			cout << (a > b ? ">" : "<");
		cout << "\n";
	}

	return 0;
}