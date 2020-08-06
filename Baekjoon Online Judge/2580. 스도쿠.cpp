#include<iostream>
#include<vector>
using namespace std;

bool check;
int map[9][9];
vector<int> D;

void Sudoku(int inx) {
	if (inx < D.size()){
		bool ch[10] = { false };
		int y = D[inx], x = D[inx + 1];
		for (int i = 0; i < 9; i++) {
			ch[map[y][i]] = true;
			ch[map[i][x]] = true;
		}
		for (int i = 0, yy = (y / 3) * 3, xx = (x / 3) * 3; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				ch[map[yy + i][xx + j]] = true;
		}
		for (int i = 1; i <= 9 && !check; i++) {
			if (!ch[i]) {
				map[y][x] = i;
				Sudoku(inx + 2);
				map[y][x] = 0;
			}
		}
	}
	else {
		check = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << map[i][j] << " ";
			cout << endl;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				D.push_back(i);
				D.push_back(j);
			}
		}
	}
	Sudoku(0);
	return 0;
}