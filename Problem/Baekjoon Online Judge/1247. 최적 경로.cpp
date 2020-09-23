// 1247. 최적 경로

#include <iostream>
using namespace std;

class XY{
private:
	int x;
	int y;
	bool visit;
public:
	XY() { x = y = 0; visit = false; }
	void Set_xy(int x, int y) { this->x = x, this->y = y; }
	int X() { return x; }
	int Y() { return y; }
	bool Visit() { return visit; }
	void Visit(bool v) { visit = v; }
	~XY() {};
};
inline int dis(XY a, XY b) { return abs(a.X() - b.X()) + abs(a.Y() - b.Y()); }
inline int min(int a, int b) { return a > b ? b : a; }

int N, Min;
void DFS(XY *node, int inx, int sum) {
	bool check = false;
	for (int i = 2; i < N + 2; i++) {
		if (!node[i].Visit()) {
			check = true;
			int Dis = dis(node[inx], node[i]);
			if (sum + Dis < Min) {
				node[i].Visit(true);
				DFS(node, i, sum + Dis);
				node[i].Visit(false);
			}
		}
	}
	if (!check)
		Min = min(Min, sum + dis(node[inx], node[1]));
}

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N;
		Min = 20000;
		XY *node = new XY[N + 2]; // node[0] : 회사, node[1] : 집
		for (int j = 0; j < N + 2; j++) {
			int x, y;
			cin >> x >> y;
			node[j].Set_xy(x, y);
		}
		DFS(node, 0, 0);
		cout << "#" << i << " " << Min << "\n";
		delete[] node;
	}
	return 0;
}