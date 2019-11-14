#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define SIZE 8

bool Cmp(string str, int len) {
	if (str.length() == len) {
		string str_p = str;
		reverse(str_p.begin(), str_p.end());
		return str.compare(str_p) == 0 ? true : false;
	}
	return false;
}

int main() {
	for (int T = 1; T <= 10; T++) {
		int len, cnt = 0;
		string map[SIZE], str;

		cin >> len;
		for (int i = 0; i < SIZE; i++) cin >> map[i];
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				for (int y = i; y < i + len && i + len <= SIZE; y++) // 세로열
					str.append(map[y], j, 1);
				cnt += Cmp(str, len);
				str.clear();
				for (int x = j; x < j + len && j + len <= SIZE; x++) // 가로열
					str.append(map[i], x, 1);
				cnt += Cmp(str, len);
				str.clear();
			}
		}
		cout << "#" << T << " " << cnt << endl;
	}
	return 0;
}