#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N, Max;
	cin >> N;
	vector <int> A(N), UP, DOWN;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++) {
		int le = 0, ri = UP.size() - 1;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			UP[mid] >= A[i] ? ri = mid - 1 : le = mid + 1;
		}
		if (le == UP.size())
			UP.push_back(A[i]);
		else
			UP[le] = A[i];
		for (int j = i + 1; j < N; j++) {
			int le = 0, ri = DOWN.size() - 1;
			while (le <= ri) {
				int mid = (le + ri) / 2;
				DOWN[mid] <= A[j] ? ri = mid - 1 : le = mid + 1;
			}
			if (le == 0 && UP.back() == A[j])
				continue;
			if (le == DOWN.size())
				DOWN.push_back(A[j]);
			else
				DOWN[le] = A[j];
		}
		Max = max(Max, (int)UP.size() + (int)DOWN.size());
		DOWN.clear();
	}
	cout << Max;
	return 0;
}