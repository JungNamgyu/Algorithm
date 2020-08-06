// 1240. 단순 2진 암호코드

#include<iostream>
#include<string>
using namespace std;

#define N 50

int main() {

	short T;
	cin >> T;

	for (int Case = 1; Case <= T; Case++) {
		string Scanner[N];
		short Code[8] = { 0 };
		short Rule[10] = { 13, 25, 19, 61, 35, 49, 47, 59, 55, 11 };

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> Scanner[i];

		int inx = 0, iny = 0;
		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) { // 끝자리 1 찾기
				if (Scanner[i][j] == '1') {
					inx = i, iny = j; // 위치 값
					break;
				}
			}
			if (Scanner[inx][iny] == '1')
				break;
		}

		for (int i = iny; i > iny - 56; i-=7) { // 2진수 -> 10진수
			for (int j = 0; j < 7; j++) {
				Code[(i - (iny - 56) - 7) / 7] += (Scanner[inx][i - j] - '0') * (1 << j);
			}
		}

		for (int i = 0; i < 8; i++) { // 10진수 -> 암호코드
			for (int j = 0; j < 10; j++) {
				if (Code[i] == Rule[j]) {
					Code[i] = j;
					break;
				}
			}
		}

		int Pass = ((Code[0] + Code[2] + Code[4] + Code[6]) * 3) + (Code[1] + Code[3] + Code[5]) + Code[7]; // 검증
		
		int Answer = 0;
		if (!(Pass % 10))
			for (int i = 0; i < 8; i++) Answer += Code[i];

		cout << "#" << Case << " " << Answer << "\n";
	}

	return 0;
}