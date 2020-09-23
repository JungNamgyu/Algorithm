#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> ground;

int main() {
	int N, M, B;

	cin >> N >> M >> B;
	ground.resize(N * M);
	for (int i = 0; i < N * M; i++)
		cin >> ground[i];

	sort(ground.begin(), ground.end());
	
	int Min = 2e9, Minh = 257;
	for(int i = ground[0]; i<=ground[N*M-1]; i++){
		int pop = 0, push = 0;
		for (int j = 0; j < N * M; j++)
			(i < ground[j]) ? pop += ground[j] - i : push += i - ground[j];

		if (push <= pop + B) {
			if (Min >= pop * 2 + push) {
				Minh = i;
				Min = pop * 2 + push;
			}
		}
	}

	cout << Min << " " << Minh << endl;

	return 0;
}