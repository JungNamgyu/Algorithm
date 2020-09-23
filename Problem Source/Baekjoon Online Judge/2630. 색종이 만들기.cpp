#include<iostream>
#include<vector>
using namespace std;

int white, blue;

void Cut(int y, int x, int r, vector < vector <int> > Paper) {
	int sum = 0;
	for (int i = y; i < y + r; i++)
		for (int j = x; j < x + r; j++)
			sum += Paper[i][j];
	if (sum == 0 || sum == r * r)
		sum ? blue += 1 : white += 1;
	else{
		Cut(y, x, r / 2, Paper);
		Cut(y + (r / 2), x, r / 2, Paper);
		Cut(y, x + (r / 2), r / 2, Paper);
		Cut(y + (r / 2), x + (r / 2), r / 2, Paper);
	}
}

int main() {
	int N;
	cin >> N;
	vector < vector <int> > Paper(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Paper[i][j];
	Cut(0, 0, N, Paper);
	cout << white << "\n" << blue;
	return 0;
}