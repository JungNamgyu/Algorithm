#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int M;
	cin >> M;
	int cup[4] = { 0,1,2,3 }, inx[4] = { 0,1,2,3 };
	while (M--) {
		int x, y;
		cin >> x >> y;
		int t = cup[inx[y]];
		cup[inx[y]] = cup[inx[x]];
		cup[inx[x]] = t;
		t = inx[y];
		inx[y] = inx[x];
		inx[x] = t;
	}
	cout << cup[1];
	return 0;
}