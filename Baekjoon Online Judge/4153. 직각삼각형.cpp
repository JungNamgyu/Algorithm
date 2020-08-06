#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {
	while (true) {
		int line[3];
		cin >> line[0] >> line[1] >> line[2];
		if (line[0] == 0) break;
		sort(line, line + 3);
		if (pow(line[0], 2) + pow(line[1], 2) == pow(line[2], 2))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}