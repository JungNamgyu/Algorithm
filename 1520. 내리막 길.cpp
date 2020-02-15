#pragma warning(disable:4996)

#include <cstdio>
#include <vector>
using namespace std;

vector < vector<int> > Map, Path, Check;
int M, N, yy[] = { -1,0,1,0 }, xx[] = { 0,1,0,-1 };

int Cache(int y, int x) {
	int& value = Path[y][x];
	if (value > 0 || !Check[y][x]) 	return value;
	for (int i = 0; i < 4; i++) {
		if (0 <= y + yy[i] && y + yy[i] < M && 0 <= x + xx[i] && x + xx[i] < N) {
			if (Map[y + yy[i]][x + xx[i]] > Map[y][x])
					value += Cache(y + yy[i], x + xx[i]);
		}
	}
	if (value == 0) 	Check[y][x] = false;
	return value;
}

int main(){
	scanf("%d%d", &M, &N);
	Map.resize(M, vector<int>(N));
	Check.resize(M, vector<int>(N, true));
	Path.resize(M, vector<int>(N, 0)); Path[0][0] = 1;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);
	printf("%d", Cache(M - 1, N - 1));
	return 0;
}