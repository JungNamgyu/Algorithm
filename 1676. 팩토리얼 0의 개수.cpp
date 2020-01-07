#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, le = 0, ri = 0;
	cin >> N;
	vector < vector<int> > D(N + 1, vector<int>(2, 0));
	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0) {
			D[i][0] = D[i / 2][0] + 1;
			le += D[i][0];
		}
		if (i % 5 == 0) {
			D[i][1] = D[i / 5][1] + 1;
			ri += D[i][1];
		}
	}
	cout << (le > ri ? ri : le);
	return 0;
}