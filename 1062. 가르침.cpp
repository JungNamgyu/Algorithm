#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Z {
	string word;
	int inx = 0;
};

Z W[51];
int N, K, D, Max = 0;
int ch = (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));

void dfs(int inx, int d, int st) {
	if (inx == K) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (d == (d | W[i].inx)) cnt++;
		}
		Max = max(Max, cnt);
	}
	else {
		for (int i = st; i < 26; i++) {
			if (!(ch & (1 << i)))
				dfs(inx + 1, d | (1 << i), i + 1);
		}
	}
}

int main() {
	cin >> N >> K; K -= 5;
	for (int i = 0; i < N; i++) {
		cin >> W[i].word;
		for (int j = 0; j < W[i].word.length(); j++) {
			if(!(ch & (1 << (W[i].word[j]-'a'))))
				W[i].inx = W[i].inx | (1 << (W[i].word[j] - 'a'));
		}
		D = D | W[i].inx;
	}
	if (0 <= K) dfs(0, 0, 0);
	cout << Max;
	return 0;
}