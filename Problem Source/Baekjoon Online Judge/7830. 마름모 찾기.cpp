// 7830. 마름모 찾기

#include <iostream>
#define SIZE 752
using namespace std;

struct Z {
	int le = 0;
	int ri = 0;
}len[SIZE][SIZE];
char map[SIZE][SIZE];
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a > b ? b : a; }

int main()
{
	int T;
	cin >> T;
	
	for (int i = 1; i <= T; i++) {
		int N, M;
		cin >> N >> M;
		for (int j = 1; j <= N; j++) cin >> &map[j][1];
		int ANS = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				len[j][k].le = len[j][k].ri = 0;
				if (map[j][k] == '1') {
					len[j][k].le = len[j - 1][k + 1].le + 1;
					len[j][k].ri = len[j - 1][k - 1].ri + 1;
					int MIN = min(len[j][k].le, len[j][k].ri);
					for (int u = MIN; u >= 1; u--) {
						if (u <= len[j - u + 1][k - u + 1].le && u <= len[j - u + 1][k + u - 1].ri) {
							ANS = max(ANS, u);
							break;
						}
					}
				}
			}
		}
		cout << "#" << i << " " << ANS << endl;
	}
	return 0;
}