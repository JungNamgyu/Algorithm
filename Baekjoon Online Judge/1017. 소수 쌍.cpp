#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t, sz, go[51];
bool p[2001], v[51];
vector<int> l[2], ans;
vector < vector<int> > edge;

void setPrime() {
	int i, j;
	p[1] = true;
	for (i = 2; i * i <= 2000; i++) {
		if (!p[i]) {
			for (j = i + i; j <= 2000; j += i)
				p[j] = true;
		}
	}
}

bool dfs(int x) {
	if (v[x]) 
		return false;
	v[x] = true;
	for (int i : edge[x]) {
		if (!p[l[t][x] + l[1-t][i]] && (go[i] == -1 || dfs(go[i]))) {
			go[i] = x;
			return true;
		}
	}
	return false;
}

int main() {
	int N;

	setPrime();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (i == 0)
			t = n % 2;
		l[n % 2].push_back(n);
	}

	int even_sz = l[0].size(), odd_sz = l[1].size();
	if (even_sz == odd_sz) {
		sz = odd_sz;

		edge.resize(sz);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				if (!p[l[t][i] + l[1 - t][j]]) {
					edge[i].push_back(j);
				}
			}
		}

		for (int i = 0; i < sz; i++) {
			if (!p[l[t][0] + l[1 - t][i]]) {
				int cnt = 1;
				fill(go, go + sz, -1);

				go[i] = 0;
				for (int j = 1; j < sz; j++) {
					fill(v, v + sz, false);
					
					v[0] = true;
					if (dfs(j)) cnt++;
				}
				if (cnt == sz)
					ans.push_back(l[1 - t][i]);
			}
		}
	}
	if (ans.empty())
		cout << "-1" << '\n';
	else {
		sort(ans.begin(), ans.end());
		for (int i : ans)
			cout << i << " ";
	}

	return 0;
}