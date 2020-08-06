#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--){
		int p;
		cin >> p;
		int Max = 0;
		string Max_name;
		while (p--) {
			int C;
			string name;
			cin >> C >> name;
			if (Max <= C) {
				Max = C;
				Max_name = name;
			}
		}
		cout << Max_name << endl;
	}
	return 0;
}