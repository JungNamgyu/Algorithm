#include<cstdio>
#include<algorithm>
using namespace std;

struct Z {
	int x, y;
}dot[100000];

bool cmp(Z a, Z b) {
	if (a.x == b.x)
		return (a.y < b.y ? true : false);
	return (a.x < b.x ? true : false);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &dot[i].x, &dot[i].y);
	sort(dot, dot + N, cmp);
	for (int i = 0; i < N; i++)
		printf("%d %d\n", dot[i].x, dot[i].y);
	return 0;
}