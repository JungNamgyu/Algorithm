#include<iostream>
#include<ctype.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	while (N--) {
		char S[31];
		cin.getline(S, 31);
		if (islower(S[0])) S[0] = toupper(S[0]);
		cout << S << endl;
	}
	return 0;
}