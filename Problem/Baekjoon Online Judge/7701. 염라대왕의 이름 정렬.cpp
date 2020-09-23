// 7701. 염라대왕의 이름 정렬

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string d1, string d2) {
	bool cmp;
	if (d1.length() == d2.length())
		return d1.compare(d2) < 0 ? true : false;
	else
		return d1.length() < d2.length() ? true : false;
}
int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;

		string name[20001];
		for (int j = 0; j < N; j++)
			cin >> name[j];
		sort(name, name + N, cmp);
		cout << "#" << i << "\n";
		for (int j = 0; j < N; j++)
			if(name[j]!=name[j+1])
				cout << name[j] << "\n";
	}
	return 0;
}