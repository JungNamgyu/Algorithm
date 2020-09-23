#include<iostream>
using namespace std;

#define M 1234567891

int main() {
	string str;
	long long L, r = 1, hash = 0;
	
	cin >> L >> str;
	for (int i = 0; i < L; r = (r * 31)%M, i++)
		hash = (hash + ((str[i] - 'a' + 1) * r)) % M;
	cout << hash;

	return 0;
}