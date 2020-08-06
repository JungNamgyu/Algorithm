#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		bool check = true;
		vector<int> V[20001];
		int v, e, V_ch[20001] = { 0 };
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int e1, e2;
			cin >> e1 >> e2;
			V[e1].push_back(e2); V[e2].push_back(e1);
		}
		for (int i = 1; i <= v; i++) {
			if (!V_ch[i]) {
				V_ch[i] = 1;
				queue<int> Q; Q.push(i);
				while (!Q.empty()) {
					int s = Q.front(); Q.pop();
					for (int i = 0; i < V[s].size(); i++) {
						if (!V_ch[V[s][i]]) {
							Q.push(V[s][i]);
							V_ch[V[s][i]] = -V_ch[s];
						}
						else if(V_ch[s] == V_ch[V[s][i]])
							check = false;
					}
					V[s].clear();
				}
			}
		}
		cout << (check ? "YES" : "NO") << endl;
	}
	return 0;
}