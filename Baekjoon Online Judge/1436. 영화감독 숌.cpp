#include<iostream>
using namespace std;

int main() {
	int N, cnt = 1;
	cin >> N;
	for (int i = 666;; i++) {
		for (int j = i; j; j /= 10) {
			if (j % 1000 == 666) {
				if (cnt == N) {
					cout << i << endl;
					return 0;
				}
				cnt++;
				break;
			}
		}
	}
}