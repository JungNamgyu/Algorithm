#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Z {
	int n, cn;
}fre[10000];
const int SD = 4000;
int N, sum, arr[500000], m, m2;

bool cmp(Z a, Z b) {
	if (a.cn == b.cn)
		return (a.n < b.n ? true : false);
	return (a.cn > b.cn ? true : false);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum += arr[i];
		fre[arr[i] + SD].cn++;
		fre[arr[i] + SD].n = arr[i];
	}
	sort(arr + 1, arr + 1 + N);
	sort(fre, fre + (SD * 2) + 1, cmp);
	cout << round((float)sum / N) << endl;							//산술평균
	cout << arr[N / 2 + 1] << endl;									//중앙값
	cout << (fre[0].cn != fre[1].cn ? fre[0].n : fre[1].n) << endl;	//2nd 최빈값
	cout << arr[N] - arr[1] << endl;									//범위
	return 0;
}