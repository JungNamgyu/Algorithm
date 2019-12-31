#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N), D;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		int le = 0, ri = D.size() - 1;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			(arr[i] > D[mid]) ? le = mid + 1 : ri = mid - 1;
		}
		if (le == D.size())
			D.push_back(arr[i]);
		else
			D[le] = arr[i];
	}
	cout << D.size();
	return 0;
}