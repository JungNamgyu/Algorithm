#include<iostream>
#include<string>
using namespace std;

int main() {
	string s, v = "aeiouAEIOU";
	while (true) {
		getline(cin, s);
		if (!s.compare("#")) break;
		int len = s.length(), cnt = 0;
		for (int i = 0; i < len; i++)
			if (v.find(s[i]) < 10)
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}