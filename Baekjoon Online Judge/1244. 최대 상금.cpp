// 1244. 최대 상금

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool two;
int Ans, Swap, Max, Swap_left;
inline int max(int a, int b) { return a > b ? a : b; }
bool cmp(char a, char b) { return a > b; }

void Find_Max(int inx, int count, string n) {
	if (stoi(n) == Max && (0 < count && count < Swap)) // 최대값인데 swap 남았을 때
		Swap_left = min(Swap_left, count);
	if (count == Swap) 
		Ans = max(Ans, stoi(n));
	else {
		for (int i = inx; i < n.size(); i++) {
			for (int j = i + 1; j < n.size(); j++) {
				if (n[i] <= n[j]) {
					swap(n[i], n[j]);
					Find_Max(i, count + 1, n);
					swap(n[i], n[j]);
				}
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		string N, M;
		cin >> N >> Swap;
		
		M = N;
		sort(M.begin(), M.begin() + M.size(), cmp);
		Max = stoi(M); //최대값 

		Ans = 0;
		Swap_left = Swap; //남은 swap 횟수
		Find_Max(0, 0, N);
		
		if (!Ans) {
			if (Swap_left % 2)
				swap(M[M.size() - 1], M[M.size() - 2]);
			Ans = stoi(M);
		}

		cout << "#" << i << " " << Ans << "\n";
	}
	return 0;
}