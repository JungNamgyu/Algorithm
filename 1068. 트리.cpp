#include<iostream>
#include<vector>
using namespace std;

int N, T[50], root, Del;
vector < vector<int> > tree;

int Tree_delete(int x) {
	if (tree[x].size() > 0) {
		int cnt = 0;
		for (int i = 0; i < tree[x].size(); i++)
			cnt += Tree_delete(tree[x][i]);
		return cnt;
	}
	return 1;
}
int main() {
	cin >> N;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> T[i];
		if (T[i] != -1) tree[T[i]].push_back(i);
		else root = i;
	}

	int e;
	cin >> Del;
	if (root == Del)
		cout << 0;
	else {
		for (e = 0; e < tree[T[Del]].size(); e++)
			if (tree[T[Del]][e] == Del) break;
		tree[T[Del]].erase(tree[T[Del]].begin() + e, tree[T[Del]].begin() + e + 1);
		cout << Tree_delete(root);
	}
	return 0;
}
