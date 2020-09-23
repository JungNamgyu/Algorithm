#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
using namespace std;

int n, root;
vector <int> In, Inx, Post;

void preorder(int In_le, int In_ri, int Post_le, int Post_ri) {
	if (In_le <= In_ri && Post_le <= Post_ri) {
		int root = Post[Post_ri];
		printf("%d ", root);
		preorder(In_le, Inx[root] - 1, Post_le, (Post_le + (Inx[root] - In_le)) - 1);
		preorder(Inx[root] + 1, In_ri, (Post_le + (Inx[root] - In_le)), Post_ri - 1);
	}
}
int main() {	
	scanf("%d", &n);
	In.resize(n);
	Post.resize(n);
	Inx.resize(n + 1);
	for (int i = 0; i < n; i++)
		scanf("%d", &In[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &Post[i]);
	for (int i = 0; i < n; i++)
		Inx[In[i]] = i;
	preorder(0, n - 1, 0, n - 1);
	return 0;
}