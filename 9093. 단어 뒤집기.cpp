#include<iostream>
#include<ctype.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		int s, e;
		char S[1001];
		cin.getline(S, 1001);
		for (s = 0, e = 0; S[e] != NULL; e++) {
			if (S[e + 1] == ' ' || S[e + 1] == NULL) {
				for (int x = 0; s + x < e - x; x++) {
					char t = S[s + x];
					S[s + x] = S[e - x];
					S[e - x] = t;
				}
				s = e + 2;
			}
		}
		cout << S << endl;
	}
	return 0;
}