#include<cstdio>
#include<vector>
using namespace std;

typedef struct Z{
	int pre, inx;
}PATH;

PATH path[1000001];

int main() {
	int N;
	scanf("%d", &N);
	vector<int> arr(N), D, ANS;

	D.push_back(-1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		int le = 1, ri = D.size() - 1;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			(arr[i] > arr[D[mid]]) ? le = mid + 1 : ri = mid - 1;
		}
		path[i].inx = i;
		path[i].pre = D[le - 1];
		if (le == D.size())
			D.push_back(i);
		else	
			D[le] = i;
	}
	printf("%d\n", D.size() - 1);
	for (int i = D.back(); i >= 0; i = path[i].pre)
		ANS.push_back(i);
	for (int i = ANS.size() - 1; i >= 0; i--)
		printf("%d ", arr[ANS[i]]);
	return 0;
}