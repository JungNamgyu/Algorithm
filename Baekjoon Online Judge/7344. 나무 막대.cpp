#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Z {
	int l, w;
	bool operator< (Z other) {
		return (l == other.l ? w < other.w : l < other.l);
	}
}stick[5001];

vector <bool> visit;

int main() {
	int T;

	cin >> T;
	while (T--) {
		int n, cnt = 0;

		cin >> n;
		visit.resize(n, false);
		for (int i = 0; i < n; i++)
			cin >> stick[i].l >> stick[i].w;

		sort(stick, stick + n);
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				cnt++;
				int w = stick[i].w;
				for (int j = i; j < n; j++) {
					if (!visit[j] && w <= stick[j].w) {
						w = stick[j].w;
						visit[j] = true;
					}
				}
			}
		}

		cout << cnt << endl;
		visit.clear();
	}

	return 0;
}