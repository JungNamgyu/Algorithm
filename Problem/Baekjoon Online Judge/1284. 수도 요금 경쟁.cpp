// 1284. 수도 요금 경쟁

#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int P, Q, R, S, W;
		cin >> P >> Q >> R >> S >> W;
		
		int A_cost = P * W;
		int B_cost = Q;
		if (W - R > 0) B_cost += (W - R)*S;

		cout << "#" << i << " " << ((A_cost > B_cost) ? B_cost : A_cost) << "\n";
	}
	return 0;
}
