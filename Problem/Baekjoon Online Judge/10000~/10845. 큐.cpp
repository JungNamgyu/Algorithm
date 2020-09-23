#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	queue <int> Q;
	while (N--) {
		string Inst;
		cin >> Inst;
		if (Inst.compare("push") == 0) {
			int X;
			cin >> X; 
			Q.push(X);
		}
		if (Inst.compare("pop") == 0) {
			cout << (Q.empty() ? -1 : Q.front()) << endl;
			if(!Q.empty())
				Q.pop();
		}
		if (Inst.compare("size") == 0) {
			cout << Q.size() << endl;
		}
		if (Inst.compare("empty") == 0) {
			cout << (Q.empty() ? 1 : 0) << endl;
		}
		if (Inst.compare("front") == 0) {
			cout << (Q.empty() ? -1 : Q.front()) << endl;
		}
		if (Inst.compare("back") == 0) {
			cout << (Q.empty() ? -1 : Q.back()) << endl;
		}
	}
	return 0;
}