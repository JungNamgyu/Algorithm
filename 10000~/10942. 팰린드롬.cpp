#pragma warning(disable:4996)

#include <cstdio>
#include <vector>
using namespace std;

int N, M;
vector <int> Seq;
vector < vector<int> > D; // 값 : 0 -> 확인 x, 1 -> 팰린드롬 x, 2 -> 팰린드롬 o

void Check(int st, int en) {
	if (st == en)
		D[st][en] = 2;
	if (st + 1 == en)
		D[st][en] = (Seq[st] == Seq[en] ? 2 : 1);
	if (Seq[st] != Seq[en])
		D[st][en] = 1;
}

int Palindrome(int st, int en) {
	Check(st, en);

	if (D[st][en] != 0)
		return D[st][en];
	else
		return D[st][en] = Palindrome(st + 1, en - 1);
}

int main() {
	scanf("%d", &N);
	Seq.resize(N + 1);
	D.resize(N + 1, vector<int>(N + 1, false));
	for (int i = 1; i <= N; i++) scanf("%d", &Seq[i]);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int st, en;
		scanf("%d%d", &st, &en);
		printf("%d\n", (Palindrome(st, en) == 2 ? 1 : 0));
	}
	return 0;
}