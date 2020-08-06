#include<iostream>
#include<vector>
using namespace std;

typedef struct Z{
	int pre, inx;
}PATH;

int main() {
	int N;
	cin >> N;
	PATH path[1001];
	vector<int> arr(N), D, ANS;

	D.push_back(-1);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		int le = 1, ri = D.size() - 1;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			(arr[i] > arr[D[mid]]) ? le = mid + 1 : ri = mid - 1;
		}
		path[i].inx = i;
		path[i].pre = D[le - 1];
		if (le == D.size())
			D.push_back(i);
		else	
			D[le] = i;
	}
	cout << D.size() - 1 << endl;
	for (int i = D.back(); i >= 0; i = path[i].pre)
		ANS.push_back(i);
	for (int i = ANS.size()-1; i >= 0; i--)
		cout << arr[ANS[i]] << " ";
	return 0;
}