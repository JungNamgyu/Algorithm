#include<iostream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N;
		string AC, X;
		deque <int> DQ;
		cin >> AC;
		cin >> N;
		cin >> X;

		int len = X.length();
		for (int i = 0; i < len; i++)
			if (X[i] == '[' || X[i] == ',' || X[i] == ']')
				X[i] = ' ';
		int x;
		stringstream ss(X);
		while (ss >> x)
			DQ.push_back(x);

		bool LEFT = true, ERROR = false;
		int M = AC.size();
		for (int i = 0; !ERROR && i < M; i++) {
			switch (AC[i]) {
			case 'R': LEFT = !LEFT; break;
			case 'D':
				if (!DQ.empty())
					LEFT ? DQ.pop_front() : DQ.pop_back();
				else
					ERROR = true;
				break;
			}
		}
		if (ERROR)
			cout << "error\n";
		else {
			cout << '[';
			for (int i = 0; i < DQ.size(); i++){
				cout << (LEFT ? DQ[i] : DQ[DQ.size() - 1 - i]);
				if (i + 1 < DQ.size())
					cout << ',';
			}
			cout << "]\n";
		}
	}
	return 0;
}