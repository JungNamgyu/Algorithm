#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= 10; j++) {
			int ANS;
			cin >> ANS;
			if ((((j - 1) % 5) + 1) == ANS) cnt++;
		}
		if (cnt == 10) cout << i << endl;
	}
	return 0;
}