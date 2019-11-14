// 11944. NN

#include <iostream>
using namespace std;

int main(){
	int N, M, len, n[5];
	cin >> N >> M;

	n[0] = N;
	for (len = 0; n[len] > 0; len++) {
		n[len + 1] = n[len] / 10;
		n[len] %= 10;
	}
	if (N*len < M) {
		for (int i = 0; i < N; i++)
			cout << N;
	}
	else {
		for (int i = 0; i < M / len; i++)
			cout << N;
		for (int i = len - 1, j = M % len; j > 0; i--, j--)
			cout << n[i];
	}
	return 0;
}