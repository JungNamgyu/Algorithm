#include <iostream>
using namespace std;

struct Z {
	int one = 0;
	int zero = 0;
}fibo[41];

int main(){
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		fibo[0].zero = fibo[1].one = 1;
		for (int i = 2; i <= 40; i++) {
			fibo[i].one = fibo[i - 1].one + fibo[i - 2].one;
			fibo[i].zero = fibo[i - 1].zero + fibo[i - 2].zero;
		}

		int N;
		cin >> N;
		cout << fibo[N].zero << " " << fibo[N].one << endl;
	}
}
