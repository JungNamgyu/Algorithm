#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

int k;
bool n[10], ch;
char sign[10], D[11], Max[11], Min[11];

void ANS(int inx) {
	if (inx == k + 1) {
		if (!ch) {
			ch = true;
			strcpy(Max, D);
		}
		strcpy(Min, D);
	}
	else {
		for (int i = 9; i >= 0; i--) {
			if (!n[i]) {
				if ((sign[inx] == '>' && D[inx - 1] > (i + '0')) || (sign[inx] == '<' && D[inx - 1] < (i + '0'))) {
					D[inx] = i + '0';
					n[i] = true;
					ANS(inx + 1);
					n[i] = false;
				}
			}
		}
	}
}

int main() {
	int i;
	cin >> k;
	for (i = 1; i <= k; i++) cin >> sign[i];
	for (i = 9; i >= 0; i--) {
		n[i] = true;
		D[0] = (i + '0');
		ANS(1);
		n[i] = false;
	}
	cout << Max << "\n" << Min;
	return 0;
}