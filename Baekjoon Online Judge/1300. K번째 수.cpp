#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, k;
	cin >> N >> k;
	int le = 1, ri = k;
	while (le <= ri) {
		int mid = (le + ri) / 2, sum = 0;
		for (int i = 1; i <= N; i++)
			sum += min(N, mid / i);
		k > sum ? le = mid + 1 : ri = mid - 1;
	}
	cout << le;
	return 0;
}