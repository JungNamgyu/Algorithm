#include<iostream>
#include<vector>
using namespace std;
#define M 1000

struct Z {
	int x[5][5] = { 0 };
};
Z A;

int N;

Z Cal(Z a, Z b) {
	Z X;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int u = 0; u < N; u++)
				X.x[i][j] += (a.x[i][u] * b.x[u][j]) % M;
	return X;
}

Z multi(long long B) {
	if (B == 1)
		return A;
	else {
		Z AA = multi(B / 2);
		Z R = Cal(AA, AA);
		if (B % 2)
			R = Cal(R, A);
		return R;
	}
}

int main() {
	long long B;
	cin >> N >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A.x[i][j];
	
	Z RES = multi(B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << RES.x[i][j] % M << " ";
		cout << endl;
	}
	return 0;
}