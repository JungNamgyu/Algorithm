#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int L, U, X;
		cin >> L >> U >> X;
		if (X < L)
			cout << "#" << i << " " << L - X << endl;
		else
			cout << "#" << i << " " << ((U < X) ? -1 : 0) << endl;
	}
	return 0;
}