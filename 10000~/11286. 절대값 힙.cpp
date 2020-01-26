#pragma warning(disable:4996)

#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
typedef long long ll;

struct cmp {
	bool operator()(const ll &a, const ll &b) {
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main() {
	int N;
	priority_queue <ll, vector<ll>, cmp> PQ;
	scanf("%d", &N);
	while (N--) {
		ll x;
		scanf("%lld", &x);
		if (x == 0) {
			printf("%lld\n", (PQ.empty() ? 0 : PQ.top()));
			if(!PQ.empty())
				PQ.pop();
		}
		else {
			PQ.push(x);
		}
	}
	return 0;
}