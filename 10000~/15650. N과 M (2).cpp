#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int seq[] = { 1,2,3,4,5,6,7,8,9 };
	bool ch[] = { 1,1,1,1,1,1,1,1,1 };
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		ch[i] = 0;
	do {
		for (int i = 0; i < M; i++) {
			if (!ch[i])
				cout << seq[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(ch, ch + M));
	return 0;
}