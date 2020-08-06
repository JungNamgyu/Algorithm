#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Z {
	char n[3];
	int s, b;
}base;

char ans[3];

bool num(int x) {
	ans[0] = (x / 100) + '0';
	ans[1] = ((x / 10) % 10) + '0';
	ans[2] = (x % 10) + '0';
	if (ans[0] != ans[1] && ans[0] != ans[2] && ans[1] != ans[2]) {
		if (!(ans[0] == '0' || ans[1] == '0' || ans[2] == '0'))
			return true;
	}
	return false;
}

int main() {
	base Q[100];
	int n, i, j, cnt = 0;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> Q[i].n >> Q[i].s >> Q[i].b;
	for (i = 123; i <= 987; i++) {
		if (num(i)) {
			for (j = 0; j < n; j++) {
				int st = 0, ba = 0;
				if (ans[0] == Q[j].n[0])
					st++;
				else if (ans[0] == Q[j].n[1] || ans[0] == Q[j].n[2])
					ba++;
				if (ans[1] == Q[j].n[1])
					st++;
				else if (ans[1] == Q[j].n[0] || ans[1] == Q[j].n[2])
					ba++;
				if (ans[2] == Q[j].n[2])
					st++;
				else if (ans[2] == Q[j].n[0] || ans[2] == Q[j].n[1])
					ba++;
				if (!(Q[j].s == st && Q[j].b == ba))
					break;
			}
			if (j == n)
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}