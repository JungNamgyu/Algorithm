#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;
const long long M = 1000000007;

int modulo(ll n) {
	if (n < 0)
		return -((-n) % M);
	return n % M;
}

ll init(vector <ll>& tree, vector<ll>& arr, int inx, int start, int end) {
	if (start == end)
		return tree[inx] = arr[start];
	return tree[inx] = modulo(init(tree, arr, inx * 2, start, (start + end) / 2) * init(tree, arr, inx * 2 + 1, (start + end) / 2 + 1, end));
}

ll query(vector <ll>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	return modulo(query(tree, node * 2, start, (start + end) / 2, left, right) * query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

ll update(vector <ll>& tree, vector<ll>& arr, int inx, int start, int end, int target) {
	if (target > end || target < start)
		return tree[inx];
	if (start == end)
		return tree[inx] = arr[target];
	return tree[inx] = modulo(update(tree, arr, inx * 2, start, (start + end) / 2, target) * update(tree, arr, inx * 2 + 1, (start + end) / 2 + 1, end, target));
}

int main() {
	int n, m, k;

	cin >> n >> m >> k;

	vector <ll> arr(n), tree(1 << ((int)ceil(log2(n)) + 1));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 0)
			arr[i] = -1;
	}

	init(tree, arr, 1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		ll a, b, c, diff;

		cin >> a >> b >> c;
		switch (a) {
		case 1: {
			arr[b - 1] = (c > 0 ? c : -1);
			update(tree, arr, 1, 0, n - 1, b - 1); break;
		}
		case 2:
			ll ans = query(tree, 1, 0, n - 1, b - 1, c - 1);
			cout << (ans > 0 ? ans : 0) << '\n'; break;
		}
	}

	return 0;
}