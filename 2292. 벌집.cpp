#include<iostream>
using namespace std;

int main() {
	int N, room = 1;
	cin >> N;
	for (int inx = 2, pass = 6; inx <= N; inx+=pass, pass += 6) room++;
	cout << room;
	return 0;
}