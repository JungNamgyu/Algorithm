#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

string e;
vector<int> N;
vector<string> S;

int main() {
	cin >> e;
	while (e.length() > e.find("+") || e.length() > e.find("-")) {
		if (e.find("+") > e.find("-")) {
			N.push_back(atoi(e.substr(0, e.find("-")).c_str()));
			S.push_back(e.substr(e.find("-"), 1));
			e = e.substr(e.find("-") + 1);
		}
		else {
			N.push_back(atoi(e.substr(0, e.find("+")).c_str()));
			S.push_back(e.substr(e.find("+"), 1));
			e = e.substr(e.find("+") + 1);
		}
	}
	N.push_back(atoi(e.c_str()));
	for (int i = 0; i < S.size();) {
		if (S[i] == "+") {
			N[i] += N[i + 1];
			S.erase(S.begin() + i);
			N.erase(N.begin() + i + 1);
		}
		else
			i++;
	}
	for (int i = 0; i < S.size();) {
		if (S[i] == "-") {
			N[i] -= N[i + 1];
			S.erase(S.begin() + i);
			N.erase(N.begin() + i + 1);
		}
	}
	cout << N[0];
	return 0;
}