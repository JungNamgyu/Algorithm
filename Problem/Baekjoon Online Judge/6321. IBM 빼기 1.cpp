#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		for (int j = 0; j < name.length(); j++) {
			name[j] += 1;
			if (name[j] > 'Z') name[j] = 'A';
		}
		cout << "String #" << i << "\n" << name << "\n\n";
	}
	return 0;
}