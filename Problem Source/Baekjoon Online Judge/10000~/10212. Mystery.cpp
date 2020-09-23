#include<iostream>
using namespace std;

int main() {
	int *n = new int;
	cout << ((long long)n % 3 ? "Yonsei" : "Korea");
	delete n;
	return 0;
}