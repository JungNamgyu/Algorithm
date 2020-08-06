#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct Z {
	int x, y;
	bool operator< (const Z &another) const {
		return x < another.x;
	}
}P;

int main() {
	int N, Max;
	cin >> N;
	vector <int> UP;
	vector < P > A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i].x >> A[i].y;
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		int le = 0, ri = UP.size() - 1;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			UP[mid] >= A[i].y ? ri = mid - 1 : le = mid + 1;
		}
		if (le == UP.size())
			UP.push_back(A[i].y);
		else
			UP[le] = A[i].y;
	}
	cout << N - UP.size();
	return 0;
}