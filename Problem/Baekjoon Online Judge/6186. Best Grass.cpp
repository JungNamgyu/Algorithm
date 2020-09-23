#include<iostream>
#include<queue>
using namespace std;

string Grass[100];
int R, C, yy[] = { -1,0,1,0 }, xx[] = { 0,1,0,-1 };

int main() {

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> Grass[i];

	int cnt = 0;
	queue < int > q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Grass[i][j] == '#') {
				cnt++;
				Grass[i][j] = '.';
				q.push(i), q.push(j);
			}
			while (!q.empty()) {
				int qy = q.front(); q.pop();
				int qx = q.front(); q.pop();

				for (int k = 0; k < 4; k++) {
					if (0 <= qy + yy[k] && qy + yy[k] < R && 0 <= qx + xx[k] && qx + xx[k] < C) {
						if (Grass[qy + yy[k]][qx + xx[k]] == '#') {
							Grass[qy+yy[k]][qx+xx[k]] = '.';
							q.push(qy + yy[k]), q.push(qx + xx[k]);
						}
					}
				}
			}
		}
	}
	cout << cnt;
	
	return 0;
}