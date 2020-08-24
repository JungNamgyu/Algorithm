#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct dot { 
	int y, x; 
};

int N;
vector <dot> c;

double getSum(int inx, int select, dot ans) {
	double Min = 1e10;

	if (select == N / 2)
		return sqrt(pow(ans.y, 2) + pow(ans.x, 2));
	
	for (int i = inx; i < N; i++)
		Min = min(Min, getSum(i + 1, select + 1, { ans.y - c[i].y - c[i].y, ans.x - c[i].x - c[i].x }));
	
	return Min;
}

int main() {
	int T;

	scanf("%d", &T);
	while (T--) {
		dot Dot = { 0,0 };

		scanf("%d", &N);
		c.resize(N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &c[i].y, &c[i].x);
			Dot.y += c[i].y, Dot.x += c[i].x;
		}

		printf("%.12lf\n", getSum(0, 0, Dot));
	}

	return 0;
}