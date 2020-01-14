#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	queue <int> Q, ANS;
	for (int i = 1; i <= N; i++)
		Q.push(i);
	for (int cn = 1; !Q.empty(); cn++) {
		if ((cn % K) > 0)
			Q.push(Q.front());
		else
			ANS.push(Q.front());
		Q.pop();
	}
	cout << '<' << ANS.front(); ANS.pop();
	while (!ANS.empty()) {
		cout << ", " << ANS.front();
		ANS.pop();
	}
	cout << '>';
}