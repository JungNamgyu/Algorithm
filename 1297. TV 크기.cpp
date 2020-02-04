#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int D, H, W;
	cin >> D >> H >> W;
	double DD = sqrt(H*H + W * W);
	cout << (int)(H * (D / DD)) << " " << (int)(W * (D / DD));
	return 0;
}