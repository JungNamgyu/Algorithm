#include<iostream>
#include<vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int N, M;
		cin >> N >> M;
		vector < pair<int, bool> > list(N, { 0, false });
		for (int i = 0; i < N; i++)
			cin >> list[i].first;
		list[M].second = true;
		int ANS = 0;
		while (true) {
			bool check = false;
			for (int j = 1; j < list.size(); j++) {
				if (list.front().first < list[j].first)
					check = true;
			}
			if (check)
				list.push_back(list.front());
			else {
				ANS++;
				if (list.front().second) {
					cout << ANS << endl;
					break;
				}
			}
			list.erase(list.begin(), list.begin() + 1);
		}
	}
	return 0;
}