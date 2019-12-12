// 1316. 그룹 단어 체커

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, i, cnt = 0;
	cin >> n;
	while (n--) {
		string word;
		bool alpha[26] = { false };
		cin >> word;
		int len = word.length();
		for (i = 0; i < len; i++) {
			if (alpha[word[i] - 'a'] && word[i] != word[i-1]) break;
			else
				alpha[word[i] - 'a'] = true;
		}
		if (i == len) cnt++;
	}
	cout << cnt;
	return 0;
}