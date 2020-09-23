#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector <int> store;
int W, H, N, dir, x, sum;

void dis() {
	if (dir == 2) x = 2 * W + H - x;
	if (dir == 3) x = 2 * (W + H) - x;
	if (dir == 4) x = W + x;
}
int abs(int X) { return (X > 0 ? X : -X); }

int main() {
	cin >> W >> H >> N;

	for (int i = 0; i < N; i++) {
		cin >> dir >> x; dis();
		store.push_back(x);
	}

	cin >> dir >> x; dis();
	if (W + H < x) {
		for (int i = 0; i < store.size(); i++) {
			if (store[i] < x - (W + H)) sum += 2 * (W + H) - x + store[i];
			else sum += abs(x - store[i]);
		}
	}
	else {
		for (int i = 0; i < store.size(); i++) {
			if (x + (W + H) < store[i]) sum += 2 * (W + H) - store[i] + x;
			else sum += abs(x - store[i]);
		}
	}
	cout << sum;
	return 0;
}