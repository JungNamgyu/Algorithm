#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return (a > b ? true : false);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int arr[11];
		for (int i = 1; i <= 10; i++)
			cin >> arr[i];
		sort(arr + 1, arr + 11, cmp);
		cout << arr[3] << endl;
	}
	return 0;
}