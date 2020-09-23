#include<iostream>
using namespace std;

int check(int x) {
	for (int i = 0; (1 << i) <= x; i++)
		if ((1 << i) == x) return 1;
	return 0;
}
int main() {
	int N;
	cin >> N;
	cout << check(N);
	return 0;
}