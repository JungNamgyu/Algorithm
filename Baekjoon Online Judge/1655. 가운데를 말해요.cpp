#pragma warning(disable:4996)

#include<cstdio>
#include<queue>
using namespace std;

int main() {
	priority_queue <int, vector<int>, less<int> > LE;
	priority_queue <int, vector<int>, greater<int> > RI;

	int N;
	scanf("%d", &N);
	

	while (N--) {
		int x;
		scanf("%d", &x);

		if (LE.empty())
			LE.push(x);
		else if (RI.empty())
			RI.push(x);
		else
			LE.push(x);

		if (LE.size() > RI.size() + 1) {
			RI.push(LE.top());
			LE.pop();
		}

		if (!RI.empty() && LE.top() > RI.top()) {
			int le = LE.top(), ri = RI.top();
			LE.pop(); RI.pop();
			LE.push(ri); RI.push(le);
		}

		printf("%d\n", LE.top());
	}
	return 0;
}