#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct Z{
	int w = 0;
	int v = 0;
}P;

int main() {
	int N, K;
	cin >> N >> K;
	vector <P> B(N + 1);
	vector < vector<int> > D(K + 1, vector<int> (N + 1));
	for (int i = 1; i <= N; i++) {
		D[0][i] = 0;
		cin >> B[i].w >> B[i].v;
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			D[i][j] = D[i][j - 1];
			if (i - B[j].w >= 0)
				D[i][j] = max(D[i - B[j].w][j - 1] + B[j].v, D[i][j]);
		}
	}
	cout << D[K][N];
	return 0;
}