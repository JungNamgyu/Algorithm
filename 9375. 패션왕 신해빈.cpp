#include<iostream>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, i, j;
		cin >> n;
		string s, v;
		vector <int> cn;
		vector <string> V;
		for (i = 0; i < n; i++) {
			cin >> s >> v;
			for (j = 0; j < V.size(); j++) {
				if (V[j].compare(v) == 0) {
					cn[j]++;
					break;
				}
			}
			if (j == V.size()) {
				V.push_back(v);
				cn.push_back(1);
			}
		}
		int sum = 1;
		for (i = 0; i < cn.size(); i++)
			sum *= (cn[i] + 1);
		cout << sum - 1 << endl;
		V.clear(); cn.clear();
	}
	return 0;
}