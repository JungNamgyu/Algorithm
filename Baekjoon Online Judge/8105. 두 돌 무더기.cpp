// 8105. 두 돌 무더기
#pragma warning (disable: 4996)
#include <cstdio>

inline void Swap(int &x, int &y) { if (x > y) { int t = x; x = y; y = t; } }

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int x, y;
		char Winner = 'A';
		scanf("%d%d", &x, &y);
		Swap(x, y);
		if (y == 4) {
			if (x == 4) Winner = 'B';
		}
		else{
			switch (y % 4) {
			case 1:
			case 3: if (x == 1) Winner = 'B'; break;
			case 2: if (x == 2) Winner = 'B'; break;
			case 0: if (x == 3) Winner = 'B'; break;
			}
		}
		printf("#%d %c\n", i, Winner);
	}
	return 0;
}