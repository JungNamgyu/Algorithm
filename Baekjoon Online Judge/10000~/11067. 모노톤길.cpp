#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Z {
	int x, y;
};

vector < Z > ans;
vector < vector<int> > caffe(100001);

int main() {
	int T;

	scanf("%d", &T);
	while (T--) {
		int n, x, y;

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			caffe[x].push_back(y);
		}
		
		int Y = 0;
		for (int i = 0; i < 100001; i++) {
			int sz = caffe[i].size();
			if (sz) {
				sort(caffe[i].begin(), caffe[i].end());

				if (Y == caffe[i][0]) {
					for (int j = 0; j < sz; j++)
						ans.push_back(Z{ i, caffe[i][j] });
					Y = caffe[i][sz - 1];
				}
				else {
					for (int j = sz - 1; j >= 0; j--)
						ans.push_back(Z{ i, caffe[i][j] });
					Y = caffe[i][0];
				}
			}
			caffe[i].clear();
		}

		int M, m;
		scanf("%d", &M);
		while (M--) {
			scanf("%d", &m);
			printf("%d %d\n", ans[m - 1].x, ans[m - 1].y);
		}

		ans.clear();
	}

	return 0;
}