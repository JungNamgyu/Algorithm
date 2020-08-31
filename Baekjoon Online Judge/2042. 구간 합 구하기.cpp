#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef long long ll;

ll init(vector <ll>& tree, vector<ll>& arr, int inx, int start, int end) {
	if (start == end)
		return tree[inx] = arr[start];
	return tree[inx] = init(tree, arr, inx * 2, start, (start + end) / 2) + init(tree, arr, inx * 2 + 1, (start + end) / 2 + 1, end);
}

ll query(vector <ll>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	return query(tree, node * 2, start, (start + end) / 2, left, right) + query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector <ll>& tree, int node, int start, int end, int inx, ll diff) {
	if (start <= inx && inx <= end) {
		tree[node] = tree[node] + diff;
		if (start != end) {
			update(tree, node * 2, start, (start + end) / 2, inx, diff);
			update(tree, node * 2 + 1, (start + end) / 2 + 1, end, inx, diff);
		}
	}
}

int main() {
	int N, M, K;

	cin >> N >> M >> K;

	vector <ll> arr(N), tree(1 << ((int)ceil(log2(N)) + 1));
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	init(tree, arr, 1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		ll a, b, c, diff;

		cin >> a >> b >> c;
		switch(a) {
		case 1: {
			diff = c - arr[b - 1];
			arr[b - 1] = c;
			update(tree, 1, 0, N - 1, b - 1, diff); break;
		}
		case 2:
			cout << query(tree, 1, 0, N - 1, b - 1, c - 1) << endl; break;
		}
	}

	return 0;
}