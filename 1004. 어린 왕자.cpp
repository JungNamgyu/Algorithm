#include<iostream>
using namespace std;

typedef struct Z{
	int x, y;
}dot;

bool inPlanet(dot a, dot b, int r) {
	float dis = (a.y - b.y)*(a.y - b.y) + (a.x - b.x)*(a.x - b.x);
	return (dis < (r*r) ? true : false);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		dot st, fi;
		int n, cnt = 0;
		cin >> st.x >> st.y >> fi.x >> fi.y;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int r;
			dot planet;
			bool ch = false;
			cin >> planet.x >> planet.y >> r;
			if (inPlanet(st, planet, r))
				ch = !ch;
			if (inPlanet(fi, planet, r))
				ch = !ch;
			if (ch)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}