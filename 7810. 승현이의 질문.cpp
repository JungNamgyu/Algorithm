// 7810. 승현이의 질문

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		int *data = new int[N + 1];

		for (int j = 1; j <= N; j++) cin >> data[j];
		sort(data + 1, data + N + 1);

		int Ans, le = 0, ri = N;
		while (le <= ri) {
			int H = (le + ri) / 2;
			(H <= data[N - H + 1]) ? (Ans = H, le = H + 1) : ri = H - 1;
		}
		cout << "#" << i << " " << Ans << endl;

		delete[] data;
	}
	return 0;
}