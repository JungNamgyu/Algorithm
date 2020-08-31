#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Z {
	int Max, Min = 2e9;
};

vector <Z> tree;
vector <int> arr;

Z init(int node, int start, int end) {
	if (start == end)
		return tree[node] = Z{ arr[start], arr[start] };

	Z le = init(node * 2, start, (start + end) / 2);
	Z ri = init(node * 2 + 1, (start + end) / 2 + 1, end);

	return tree[node] = Z{ max(le.Max, ri.Max), min(le.Min, ri.Min) };
}

Z query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return Z{ 0, (int)2e9 };
	if (left <= start && end <= right)
		return tree[node];

	Z le = query(node * 2, start, (start + end) / 2, left, right);
	Z ri = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

	return Z{ max(le.Max, ri.Max), min(le.Min, ri.Min) };
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;

	cin >> N >> M;

	arr.resize(N);
	tree.resize(1 << ((int)ceil(log2(N)) + 1));

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	init(1, 0, N - 1);

	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		
		Z ans = query(1, 0, N - 1, a - 1, b - 1);
		
		cout << ans.Min << " " << ans.Max << '\n';
	}

	return 0;
}