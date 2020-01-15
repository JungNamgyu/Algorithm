#include<iostream>
using namespace std;

int main() {
	int N, ANS = 0;
	cin >> N;
	for (int i = 1; N > 0; i++) {
		if (i > N && (N/i) > 0) {
				ANS += N / i;
				N %= i;
				i = 1;
		}
		else{
			if (N < i)
				i = 1;
			N -= i;
			ANS++;
		}
	}
	cout << ANS;
	return 0;
}