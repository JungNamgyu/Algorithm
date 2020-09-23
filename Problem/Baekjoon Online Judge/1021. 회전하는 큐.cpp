#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	deque <int> DQ;
	vector <int> list;
	for (int i = 1; i <= N; i++)
		DQ.push_back(i);
	int ANS = 0;
	for (int x, i = 0; i < M; i++) {
		cin >> x;
		int inx = 0;
		while (DQ[inx] != x) inx++;
		if (inx <= (DQ.size() - (inx + 1))) {
			for (int i = 0; i < inx; i++, ANS++) {
				DQ.push_back(DQ.front());
				DQ.pop_front();
			}
		}
		else {
			for (int i = 0; i <= DQ.size() - (inx + 1); i++, ANS++) {
				DQ.push_front(DQ.back());
				DQ.pop_back();
			}
		}
		DQ.pop_front();
	}
	cout << ANS;
	return 0;
}