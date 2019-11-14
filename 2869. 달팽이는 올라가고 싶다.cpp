// 2869. 달팽이는 올라가고 싶다

#include <iostream>
using namespace std;

int main(){
	int A, B, V, Ans;
	cin >> A >> B >> V;
	Ans = ((V - A) / (A - B));
	if ((V - A) % (A - B)) Ans++;
	cout << Ans + 1;

	return 0;
}