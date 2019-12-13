// 5596. 시험 점수

#include <iostream>
#include <algorithm>
using namespace std;

int a[4], b[4], a_sum, b_sum;

int main(){
	for (int i = 0; i < 4; i++) {
		cin >> a[i]; a_sum += a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> b[i]; b_sum += b[i];
	}
	cout << max(a_sum, b_sum);
	return 0;
}