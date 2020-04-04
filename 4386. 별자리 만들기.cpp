#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Z
{
	float x, y;
};
struct ZZ
{
	float d;
	int a, b;
	bool operator<(const ZZ x)
	{
		return this->d < x.d;
	}
};

float sum;
int n, cnt;
vector<Z> star;
vector<ZZ> dis;
vector<int> group;

float star_dis(int a, int b)
{
	return sqrt(pow(star[a].y - star[b].y, 2) + pow(star[a].x - star[b].x, 2));
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
	if (pa != pb){
		group[pb] = pa;
		return false;
	}
	return true;
}

int main()
{
	int i, j;

	scanf("%d", &n);
	star.resize(n);
	group.resize(n);

	for (i = 0; i < n; i++)
	{
		group[i] = i;
		scanf("%f%f", &star[i].x, &star[i].y);
		for (j = 0; j < i; j++)
			dis.push_back(ZZ{star_dis(j, i), j, i});
	}

	sort(dis.begin(), dis.end());
	for (i = 0; cnt < n - 1 && i < dis.size(); i++)
	{
		if (Union(dis[i].a, dis[i].b))
			continue;
		cnt++;
		sum += dis[i].d;
	}
	printf("%.2f", sum);
	return 0;
}