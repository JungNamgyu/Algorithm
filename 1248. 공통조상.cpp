// 1248. 공통조상

#include <iostream>
using namespace std;

class Tree {
private:
	int num;
	int size;
	bool check;
	Tree *Parent_node;
	Tree *left_node;
	Tree *right_node;
public:
	Tree();
	void Set_num(int num); // 노드 값 셋팅
	int Sub_size(Tree *node); // subtree size 확인
	void Set_node(Tree *node); // 노드 연결 (우선순위 le -> ri)
	int LCA(Tree *node); //최저공통조상 Lowest Common Ancestor
	~Tree() {};
};

Tree::Tree() {
	num = size = 0;
	check = false;
	Parent_node = left_node = right_node = NULL;

}

void Tree::Set_num(int num) {
	this->num = num;
}

int Tree::Sub_size(Tree *node) {
	node->size = 1;
	if (node->left_node != NULL)
		node->size += Sub_size(node->left_node);
	if (node->right_node != NULL)
		node->size += Sub_size(node->right_node);
	return node->size;
}

void Tree::Set_node(Tree *node) {
	node->Parent_node = this;
	if (this->left_node != NULL)
		this->right_node = node;
	else
		this->left_node = node;
}

int Tree::LCA(Tree *node) {
	if (node->check)
		return node->num;
	else
		node->check = true;
	if (node->Parent_node == NULL)
		return 0;
	return LCA(node->Parent_node);
}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int V, E, P1, P2;
		cin >> V >> E >> P1 >> P2;

		Tree *tree = new Tree[V + 1];
		for (int j = 1; j <= V; j++) tree[j].Set_num(j);
		for (int j = 0; j < E; j++) {
			int Parent, Child;
			cin >> Parent >> Child;
			tree[Parent].Set_node(tree + Child);
		}
		tree->LCA(tree + P1);
		int lca = tree->LCA(tree + P2);

		cout << "#" << i << " " << lca << " " << tree->Sub_size(tree + lca) << "\n";
		delete[] tree;
	}
	return 0;
}