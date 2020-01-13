#pragma warning (disable:4996)

#include<cstdio>
#include<queue>
using namespace std;

int main() {
	int N;
	priority_queue <int> Max_heap;
	scanf("%d", &N);
	while (N--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (Max_heap.empty())
				printf("%d\n", 0);
			else {
				printf("%d\n", Max_heap.top());
				Max_heap.pop();
			}
		}
		else
			Max_heap.push(x);
	}
	return 0;
}