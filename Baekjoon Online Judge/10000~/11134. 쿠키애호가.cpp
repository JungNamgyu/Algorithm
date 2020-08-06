#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
		int N, C;
		cin >> N >> C;
		cout << (int)ceil(1. * N / C) << endl;
	}
	return 0;
}