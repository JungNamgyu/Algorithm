#include<iostream>
using namespace std;

int cnt[3];
int Paper[2187][2187];

bool check(int y, int x, int r) {
	for (int i = y; i < y + r; i++)
		for (int j = x; j < x + r; j++)
			if (Paper[y][x] != Paper[i][j])
				return false;
	return true;
}

void Cut(int y, int x, int r) {
	if (check(y, x, r))
		cnt[Paper[y][x] + 1]++;
	else{
		for (int i = 0; i < r; i += (r / 3))
			for (int j = 0; j < r; j += (r / 3))
				Cut(y + i, x + j, (r / 3));
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Paper[i][j];
	Cut(0, 0, N);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << endl;
	return 0;
}