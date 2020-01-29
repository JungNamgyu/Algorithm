#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Z {
	int dis = 2e9;
	bool ch = false;
}D;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, t;
		int s, g, h;
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		vector<int> Dest(t);
		vector<D> Dis(n + 1);
		vector<bool> check(n + 1, false);
		vector< vector<int> > Edge(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			Edge[a].push_back(b); Edge[a].push_back(d);
			Edge[b].push_back(a); Edge[b].push_back(d);
		}
		for (int i = 0; i < t; i++)
			cin >> Dest[i];
		sort(Dest.begin(), Dest.end());
		queue <int> Q;
		Q.push(s); Dis[s].dis = 0;
		while (!Q.empty()) {
			int x = Q.front(); Q.pop();
			int sz = Edge[x].size();
			for (int i = 0; i < sz; i += 2) {
				int go = Edge[x][i], dis = Edge[x][i + 1];
				if (Dis[go].dis > Dis[x].dis + dis) {
					Dis[go].dis = Dis[x].dis + dis;
					Dis[go].ch = ((x == g && go == h || x == h && go == g) ? true : Dis[x].ch);
				}
				else if (Dis[go].dis == Dis[x].dis + dis) {
					Dis[go].ch = ((x == g && go == h || x == h && go == g || Dis[go].ch == true) ? true : Dis[x].ch);
				}
			}
			int Min = 2e9, inx = -1;
			for (int i = 1; i <= n; i++) {
				if (!check[i] && Min > Dis[i].dis) {
					inx = i;
					Min = Dis[i].dis;
				}
			}
			if (inx != -1) {
				Q.push(inx);
				check[inx] = true;
			}
		}
		for (int i = 0; i < t; i++) {
			if (Dis[Dest[i]].ch)
				cout << Dest[i] << " ";
		}
		cout << endl;
	}
	return 0;
}