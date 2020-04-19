#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector <int> Cnt;
vector < vector<int> > Line;
priority_queue <int, vector<int>, greater<int> > Q;

int main() {	
	scanf("%d%d", &N, &M);
	Line.resize(N + 1);
	Cnt.resize(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int A, B;
		scanf("%d%d", &A, &B);
		Line[A].push_back(B), Cnt[B]++;
	}

	for (int i = 1; i <= N; i++)
		if (Cnt[i] == 0) Q.push(i);

	while (!Q.empty()) {
		int S = Q.top(); Q.pop();
		printf("%d ", S);

		int sz = Line[S].size();
		for (int i = 0; i < sz; i++) {
			Cnt[Line[S][i]]--;
			if (Cnt[Line[S][i]] == 0) Q.push(Line[S][i]);
		}
	}
	return 0;
}