#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		char message[101], Cry[27];
		cin.getline(message, 101);
		cin.getline(Cry, 27);
		for (int i = 0; i < strlen(message); i++)
			if(!isblank(message[i]))
				message[i] = Cry[message[i] - 'A'];
		cout << message << endl;
	}
	return 0;
}