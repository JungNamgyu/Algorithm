#include<iostream>
#include<queue>
using namespace std;

queue <int> Q;
int Row[200001], Path[200001], p[200001];

int main() {
	int N, K;
	cin >> N >> K;
	Q.push(N);
	Path[N] = -1;
	while (!Path[K] && !Row[K]) {
		int x = Q.front(); Q.pop();
		if (x - 1 >= 0) {
			if (!Path[x - 1] && !Row[x - 1]) {
				Q.push(x - 1);
				Path[x - 1] = x;
				Row[x - 1] = Row[x] + 1;
			}
		}
		if (x + 1 <= 200000) {
			if (!Path[x + 1] && !Row[x + 1]) {
				Q.push(x + 1);
				Path[x + 1] = x;
				Row[x + 1] = Row[x] + 1;
			}
		}
		if (x * 2 <= 200000) {
			if (!Path[x * 2] && !Row[x * 2]) {
				Q.push(x * 2);
				Path[x * 2] = x;
				Row[x * 2] = Row[x] + 1;
			}
		}
	}
	cout << Row[K] << "\n";
	int go = K, cnt = 0;
	while (go != -1) {
		p[cnt++] = go;
		go = Path[go];
	}
	while(cnt--) cout << p[cnt]<< " ";
	return 0;
}