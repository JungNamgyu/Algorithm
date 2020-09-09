#pragma warning(disable:4996)

#include<cstdio>
#include<vector>
using namespace std;

bool check;
vector<int> ans;

void remove(vector<int> a, int erase, int length) {
	if (erase <= length / 2 && !check) {
		int sz = a.size(), odd = 0, even = 0;
		for (int i = 0; i < sz; i++) {
			(i % 2 ? odd : even) += a[i];
		}
		if (odd == even) {
			for (int& value : a)
				ans.push_back(value);
			check = true;
		}
		else {
			for (int i = (odd > even ? 1 : 0); i < sz; i += 2) {
				if (a[i] == 1) {
					a.erase(a.begin() + i);
					remove(a, erase + 1, length);
					a.insert(a.begin() + i, 1);

					if (check)
						break;
				}
			}
		}
	}
}

int main() {
	int T;

	scanf("%d", &T);
	while (T--) {
		int n;

		scanf("%d", &n);
		vector<int> a(n);
		for (int& value : a)
			scanf("%d", &value);

		remove(a, 0, a.size());

		printf("%d\n", ans.size());
		for (int& value : ans)
			printf("%d ", value);
		printf("\n");

		ans.clear();
		check = false;
	}
	return 0;
}