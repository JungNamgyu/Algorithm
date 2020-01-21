#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector <int> Card(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Card[i]);
	sort(Card.begin(), Card.end());
	int M;
	scanf("%d", &M);
	vector <int> Cnt(M);
	for (int i = 0; i < M; i++)
		scanf("%d", &Cnt[i]);
	for (int i = 0; i < M; i++) {
		int le = 0, ri = N - 1;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			if (Card[mid] <= Cnt[i])
				le = mid + 1;
			else
				ri = mid - 1;
		}
		int HIGH = le;
		le = 0, ri = N - 1;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			if (Card[mid] < Cnt[i])
				le = mid + 1;
			else
				ri = mid - 1;
		}
		int LOW = le;
		printf("%d ", HIGH - LOW);
	}
	return 0;
}