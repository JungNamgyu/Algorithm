#include<iostream>
#include<string>
using namespace std;

string coin[8] = { "TTT","TTH","THT","THH","HTT","HTH","HHT","HHH" };

int main() {
	int p;
	cin >> p;
	while (p--) {
		string s;
		int cnt[8] = { 0 };
		cin >> s;
		for (int i = 0; i < 40; i++) {
			string ss = s.substr(i, 3);
			for (int j = 0; j < 8; j++)
				if (ss.compare(coin[j]) == 0) cnt[j]++;
		}
		for (int i = 0; i < 8; i++)
			cout << cnt[i] << " ";
		cout << "\n";
	}
	return 0;
}