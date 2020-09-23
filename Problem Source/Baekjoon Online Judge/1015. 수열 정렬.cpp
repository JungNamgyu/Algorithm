#include<iostream>
#include<algorithm>
using namespace std;

struct Z {
	int n, inx;
}A[50];
int P[50];

bool cmp(Z a, Z b) {
	if (a.n == b.n)
		return (a.inx < b.inx ? true : false);
	return (a.n < b.n ? true : false);
}

int main() {
	int N;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].n;
		A[i].inx = i;
	}
	sort(A, A + N, cmp);
	for (int i = 0; i < N; i++)
		P[A[i].inx] = i;
	for (int i = 0; i < N; i++)
		cout << P[i] << " ";
	return 0;
}