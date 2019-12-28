#include<iostream>
#include<algorithm>
using namespace std;

int N, A[100], op[4], ch[4], Max = -1e9, Min = 1e9; // +, -, *, /

void Cal(int inx, int r) {
	if (ch[0] == op[0] && ch[1] == op[1] && ch[2] == op[2] && ch[3] == op[3]) {
		Max = max(r, Max);
		Min = min(r, Min);
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (ch[i] < op[i]) {
				ch[i]++;
				switch (i) {
				case 0: Cal(inx + 1, r + A[inx]); break;
				case 1: Cal(inx + 1, r - A[inx]); break;
				case 2: Cal(inx + 1, r * A[inx]); break;
				case 3: Cal(inx + 1, r / A[inx]); break;
				}
				ch[i]--;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	Cal(1, A[0]);
	cout << Max << "\n" << Min;
	return 0;
}