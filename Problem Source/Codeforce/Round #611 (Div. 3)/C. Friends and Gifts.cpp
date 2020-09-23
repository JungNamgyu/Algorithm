#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	n += 1;
	vector<bool> ch(n);
	vector<int> f(n), o, t;
	for (int i = 1; i < n; i++) {
		cin >> f[i];
		ch[f[i]] = true;
	}
	for (int i = 1; i < n; i++) {
		if (!ch[i])
			f[i] ? o.push_back(i) : t.push_back(i);
	}
	if (t.size() == 1) {
		f[t.front()] = o.front();
		o.erase(o.begin());
		o.push_back(t.front());
	}
	else {
		for (int i = 0; i < t.size(); i++)
			f[t[i]] = t[(i + 1) % t.size()];
	}
	for (int i = 1, j = 0; j < o.size(); i++) {
		if (!f[i])
			f[i] = o[j++];
	}
	for (int i = 1; i < n; i++) {
		cout << f[i] << " ";
	}
	return 0;
}
