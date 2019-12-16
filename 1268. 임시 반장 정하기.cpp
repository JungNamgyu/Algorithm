#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int st[1001][6];
vector<int> c[6][10];

int main() {
	int n, Max = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf("%d", &st[i][j]);
			c[j][st[i][j]].push_back(i);
		}
	}
	for (int s = 1; s <= n; s++) {
		bool ch[1001] = { false };
		ch[s] = true;
		for (int i = 1; i <= 5; i++) {
			int l = c[i][st[s][i]].size();
			for (int k = 0; k < l; k++) {
				if (!ch[c[i][st[s][i]][k]]) {
					st[s][0]++;
					ch[c[i][st[s][i]][k]] = true;
				}
			}
		}
		if (st[s][0] > st[Max][0]) Max = s;
	}
	printf("%d", Max);
	return 0;
}