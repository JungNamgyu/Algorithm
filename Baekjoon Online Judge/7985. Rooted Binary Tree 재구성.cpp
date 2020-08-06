// 7985. Rooted Binary Tree 재구성

#include <iostream>
using namespace std;

int node_N;
void Re_tree(int *inorder, int *tree, int inx, int t_inx, int r) {
	tree[t_inx] = inorder[inx];
	if (0 < r) {
		Re_tree(inorder, tree, inx - r, t_inx * 2, r / 2);
		Re_tree(inorder, tree, inx + r, t_inx * 2 + 1, r / 2);
	}
}
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int K;
		cin >> K;
		node_N = 1 << K;
		int *inorder = new int[node_N], *tree = new int[node_N];
		for (int j = 1; j < node_N; j++)
			cin >> inorder[j];
		Re_tree(inorder, tree, node_N / 2, 1, node_N / 4);
		cout << "#" << i << " ";
		for (int j = 1; j <= K; j++) {
			int j_N = (1 << j);
			for (int u = j_N / 2; u < j_N; u++)
				cout << tree[u] << " ";
			cout << endl;
		}
	}
	return 0;
}