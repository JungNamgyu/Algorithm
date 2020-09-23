#pragma warning(disable: 4996)

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	queue <int> Q;
	while (N--) {
		char Inst[6] = { 0 };
		scanf("%s", Inst);
		if (strcmp(Inst, "push") == 0) {
			int X;
			scanf("%d", &X);
			Q.push(X);
		}
		if (strcmp(Inst, "pop") == 0) {
			printf("%d\n",(Q.empty() ? -1 : Q.front()));
			if (!Q.empty())
				Q.pop();
		}
		if (strcmp(Inst, "size") == 0) {
			printf("%d\n", Q.size());
		}
		if (strcmp(Inst, "empty") == 0) {
			printf("%d\n", (Q.empty() ? 1 : 0));
		}
		if (strcmp(Inst, "front") == 0) {
			printf("%d\n", (Q.empty() ? -1 : Q.front()));
		}
		if (strcmp(Inst, "back") == 0) {
			printf("%d\n", (Q.empty() ? -1 : Q.back()));
		}
	}
	return 0;
}