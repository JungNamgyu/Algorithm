#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Z
{
	long long x, y;
};
struct ZZ
{
	double d;
	int a, b;
	bool operator<(const ZZ x)
	{
		return this->d < x.d;
	}
};

double sum;
int N, M, cnt;
vector<ZZ> dis;
vector<Z> space;
vector<int> group;

double space_dis(int a, int b)
{
	long long D = (space[a].y - space[b].y) * (space[a].y - space[b].y) + (space[a].x - space[b].x) * (space[a].x - space[b].x);
	return sqrt(D);
}

int Find(int a)
{
	if (group[a] == a)
		return a;
	return group[a] = Find(group[a]);
}

bool Union(int a, int b)
{
	int pa = Find(a), pb = Find(b);
	if (pa != pb)
	{
		group[pb] = pa;
		return false;
	}
	return true;
}

int main()
{
	int i, j;

	scanf("%d%d", &N, &M);
	space.resize(N + 1);
	group.resize(N + 1);

	for (i = 1; i <= N; i++)
	{
		group[i] = i;
		scanf("%ld%ld", &space[i].x, &space[i].y);
		for (j = 1; j < i; j++)
			dis.push_back(ZZ{space_dis(j, i), j, i});
	}

	sort(dis.begin(), dis.end());
	for (i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(!Union(a, b)) cnt++;
	}
	for (i = 0; cnt < N - 1 && i < dis.size(); i++)
	{
		if (Union(dis[i].a, dis[i].b))
			continue;
		cnt++;
		sum += dis[i].d;
	}
	printf("%.2lf", sum);
	return 0;
}