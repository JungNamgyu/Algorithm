#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N), D;

	D.push_back(-1);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		int le = 1, ri = D.size() - 1;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			(arr[i] < arr[D[mid]]) ? le = mid + 1 : ri = mid - 1;
		}
		if (le == D.size())
			D.push_back(i);
		else	
			D[le] = i;
	}
	cout << D.size() - 1;
	return 0;
}