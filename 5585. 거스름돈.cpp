#include <iostream>
using namespace std;

int main()
{
	int pay, ans = 0, coin[] = { 500,100,50,10,5,1 };
	cin >> pay;
	pay = 1000 - pay;
	for (int i = 0; pay || i < 6; i++) {
		ans += pay / coin[i];
		pay %= coin[i];
	}
	cout << ans;
	return 0;
}