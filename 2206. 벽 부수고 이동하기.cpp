#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

typedef struct Z {
	int y = 0, x = 0;
	bool check = false;
}location;

int yy[] = { -1,0,1,0 }, xx[] = { 0,1,0,-1 };

bool InMap(location Inx, int N, int M) {
	if (0 <= Inx.y && Inx.y < N && 0 <= Inx.x && Inx.x < M)
		return true;
	else
		return false;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector <string> Map(N);
	vector < vector<int> > Cnt(N, vector<int>(M, 2e9)), Cnt_Break(N, vector<int>(M, 2e9));
	for (int i = 0; i < N; i++)
		cin >> Map[i];

	location X;
	Cnt[0][0] = Cnt_Break[0][0] = 1;
	queue < location > Q; Q.push(X);
	while (!Q.empty()) {
		X = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			location go;
			go.check = X.check, go.y = X.y + yy[i], go.x = X.x + xx[i];
			if (InMap(go, N, M)) {
				if (Map[go.y][go.x] == '0'){
					if (X.check && Cnt_Break[go.y][go.x] > Cnt_Break[X.y][X.x] + 1) {
						Cnt_Break[go.y][go.x] = Cnt_Break[X.y][X.x] + 1;
						Q.push(go);
					}
					else if(!X.check && Cnt[go.y][go.x] > Cnt[X.y][X.x] + 1) {
						Cnt[go.y][go.x] = Cnt[X.y][X.x] + 1;
						Q.push(go);
					}
				}
				else{
					if (!X.check && Cnt_Break[go.y][go.x] > Cnt[X.y][X.x] + 1) {
						Cnt_Break[go.y][go.x] = Cnt[X.y][X.x] + 1;
						go.check = true;
						Q.push(go);
					}
				}
			}
		}
	}
	if (Cnt[N - 1][M - 1] > Cnt_Break[N - 1][M - 1])
		cout << Cnt_Break[N - 1][M - 1];
	else if (Cnt[N - 1][M - 1] == 2e9)
		cout << -1;
	else
		cout << Cnt[N - 1][M - 1];
	return 0;
}