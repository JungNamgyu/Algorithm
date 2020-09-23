#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N, M;
		vector < vector<int> > G;

		cin >> N >> M;
		G.resize(N + 1, vector<int>(M + 1, 0));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> G[i][j];
				G[i][j] += G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1];
			}
		}
		for (int i = 5; i <= N; i++) {
			for (int j = 5; j <= M; j++) {
				Answer = max(Answer, G[i][j] - G[i - 5][j] - G[i][j - 5] + G[i - 5][j - 5]);
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}