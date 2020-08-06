// 9550. 아이들은 사탕을 좋아해

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int candy, child = 0;
		for (int i = 0; i < n; i++) {
			cin >> candy; child += (candy / k);
		}
		cout << child << endl;
	}
	return 0;
}