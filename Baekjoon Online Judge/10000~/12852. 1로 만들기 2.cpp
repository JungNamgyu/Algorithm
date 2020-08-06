#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> Cache, Path;

int main() {
	cin >> N;

	Path.resize(N + 1, 2e9); Path[1] = 0;
	Cache.resize(N + 1, 2e9); Cache[1] = 0;

	for (int i = 2; i <= N; i++) {
		Path[i] = i - 1;
		Cache[i] = Cache[i - 1] + 1;
		if (i % 3 == 0 && Cache[i / 3] < Cache[i]) {
			Path[i] = i / 3;
			Cache[i] = Cache[i / 3] + 1;
		}
		if (i % 2 == 0 && Cache[i / 2] < Cache[i]) {
			Path[i] = i / 2;
			Cache[i] = Cache[i / 2] + 1;
		}
	}
	cout << Cache[N] << "\n";
	int go = N;
	while (go) {
		cout << go << " ";
		go = Path[go];
	}
	return 0;
}