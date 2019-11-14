// 6730. 장애물 경주 난이도

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;

		int B[100];
		for (int j = 0; j < N; j++)
			cin >> B[j];

		int Up = 0, Down = 0;
		for (int j = 1; j < N; j++) {
			if (B[j - 1] < B[j])
				Up = max(Up, B[j] - B[j - 1]);
			else
				Down = max(Down, B[j - 1] - B[j]);
		}
		cout << "#" << i << " " << Up << " " << Down << endl;
	}
}