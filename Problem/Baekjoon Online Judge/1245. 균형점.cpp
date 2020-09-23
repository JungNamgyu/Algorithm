// 1245. 균형점

#include <iostream>
using namespace std;

struct Point { int x, m; }; // 자성체 (x : 위치, m : 질량)
inline double F(int m1, int m2, double d) { return ((m1 * m2) / (d * d)); } //인력을 구하는 공식(m : 질량, d : 거리)

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;

		Point *point = new Point[N];
		for (int j = 0; j < N; j++)  cin >> point[j].x; // x좌표 입력
		for (int j = 0; j < N; j++)  cin >> point[j].m; // 질량값 입력

		cout << fixed;
		cout.precision(10);
		cout << "#" << i;
		for (int j = 0; j < N - 1; j++) {
			double mid;
			double le = point[j].x, ri = point[j + 1].x;
			while (1.0e-12 <= ri - le) { // 평균점의 오차 (소수점 12자리)
				mid = (le + ri) / 2;
				double le_F = 0, ri_F = 0;
				for (int k = 0; k < N; k++) {
					(point[k].x <= mid ? le_F : ri_F) += F(point[k].m, 1, point[k].x - mid);
				}
				(le_F < ri_F ? ri : le) = mid;
			}
			cout << " " << mid;
		}
		cout << "\n";
		delete[] point;
	}

	return 0;
}