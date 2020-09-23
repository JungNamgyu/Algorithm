// 1251. 하나로

#include <iostream>
#include <cmath>
using namespace std;

struct XY {
	int x;
	int y;
};

double E;
long long int Prim(int, int, XY*);
inline double cost(XY a, XY b) { return E*(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0)); }

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;

		XY *Island = new XY[N];
		for (int j = 0; j < N; j++) cin >> Island[j].x;
		for (int j = 0; j < N; j++) cin >> Island[j].y;
		cin >> E;

		cout << "#" << i << " " << Prim(0, N, Island) << "\n";
	}
	return 0;
}


long long int Prim(int inx, int size, XY *Island) {
	double *prim[2], sum = 0;
	bool *ch = new bool[size];
	ch[0] = true;
	prim[0] = new double[size], prim[1] = new double[size]; // 0 : 연결 비용, 1 : 연결 노드
	for (int i = 1; i < size; i++) {
		ch[i] = false;
		prim[0][i] = INT64_MAX, prim[1][i] = -1;
	}
	for (int i = 0; i < size - 1; i++) {
		int min_inx;
		double min = INT64_MAX;
		for (int j = 0; j < size; j++) {
			if (!ch[j]) {
				if (prim[0][j] > cost(Island[inx], Island[j])) {
					prim[1][j] = inx;
					prim[0][j] = cost(Island[inx], Island[j]);
				}
				if (min > prim[0][j]) {
					min_inx = j;
					min = prim[0][j];
				}
			}
		}
		inx = min_inx;
		ch[inx] = true;
		sum += prim[0][inx];
	}
	return sum + 0.5;
}