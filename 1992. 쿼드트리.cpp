#include<iostream>
#include<vector>
#include<string>
using namespace std;

int white, blue;

void Cut(int y, int x, int r, vector < vector <int> > Paper) {
	int sum = 0;
	for (int i = y; i < y + r; i++)
		for (int j = x; j < x + r; j++)
			sum += Paper[i][j];
	if (sum == 0 || sum == r * r)
		cout << (sum ? 1 : 0);
	else{
		cout << '(';
		Cut(y, x, r / 2, Paper);
		Cut(y, x + (r / 2), r / 2, Paper);
		Cut(y + (r / 2), x, r / 2, Paper);
		Cut(y + (r / 2), x + (r / 2), r / 2, Paper);
		cout << ')';
	}
}

int main() {
	int N;
	cin >> N;
	vector < vector <int> > Paper(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			Paper[i][j] = (s[j] - '0');
		}
	}
	Cut(0, 0, N, Paper);
	return 0;
}