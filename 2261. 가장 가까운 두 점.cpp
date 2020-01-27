#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


typedef struct Z {
	int y, x;
}Dot;
Dot dot[100000];

bool cmp_x(Dot a, Dot b) { return a.x < b.x; }
bool cmp_y(Dot a, Dot b) { return a.y < b.y; }
inline int Dis(Dot a, Dot b) { return pow(a.x - b.x, 2) + pow(a.y - b.y, 2); }

int Line(int le, int ri) {
	if (le < ri) {
		int mid = (le + ri) / 2;
		int d = min(Line(le, mid - 1), Line(mid + 1, ri));
		vector<Dot> dd;
		for (int i = le; i <= ri; i++) {
			if (pow(dot[mid].x - dot[i].x, 2) <= d)
				dd.push_back(dot[i]);
		}
		sort(dd.begin(), dd.end(), cmp_y);
		int dd_sz = dd.size();
		for (int i = 0; i < dd_sz; i++) {
			for (int j = i + 1; j < dd_sz && (dd[j].y-dd[i].y) < d; j++)
				d = min(d, Dis(dd[i], dd[j]));
		}
		return d;
	}
	else
		return 2e9;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &dot[i].x, &dot[i].y);
	sort(dot, dot + n, cmp_x);
	printf("%d", Line(0, n - 1));
	return 0;
}