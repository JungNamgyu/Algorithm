#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main() {
	int N;
	cin >> N;
	deque <int> DQ;
	while (N--) {
		string Inst;
		cin >> Inst;
		if (Inst.compare("push_front") == 0) {
			int X;
			cin >> X; 
			DQ.push_front(X);
		}
		if (Inst.compare("push_back") == 0) {
			int X;
			cin >> X;
			DQ.push_back(X);
		}
		if (Inst.compare("pop_front") == 0) {
			cout << (DQ.empty() ? -1 : DQ.front()) << endl;
			if(!DQ.empty())
				DQ.pop_front();
		}
		if (Inst.compare("pop_back") == 0) {
			cout << (DQ.empty() ? -1 : DQ.back()) << endl;
			if (!DQ.empty())
				DQ.pop_back();
		}
		if (Inst.compare("size") == 0) {
			cout << DQ.size() << endl;
		}
		if (Inst.compare("empty") == 0) {
			cout << (DQ.empty() ? 1 : 0) << endl;
		}
		if (Inst.compare("front") == 0) {
			cout << (DQ.empty() ? -1 : DQ.front()) << endl;
		}
		if (Inst.compare("back") == 0) {
			cout << (DQ.empty() ? -1 : DQ.back()) << endl;
		}
	}
	return 0;
}