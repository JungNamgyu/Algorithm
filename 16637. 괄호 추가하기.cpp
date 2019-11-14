// 16637. 괄호 추가하기

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

inline int stoi(char data) { return data - '0'; }
inline long long oper(long long a, long long b, char sign) {
	switch (sign) {
	case '+': return a + b;
	case '*': return a * b;
	case '-': return a - b;
	}
}

int cal(string data, int N) {
	string sign;
	int num[10], op[10];
	long long Max[10], Min[10];
	for (int i = 0; i < N; i++) {
		if (i % 2)
			sign.append(data, i, 1);
		else 
			num[i/2] = stoi(data[i]);
	}
	for (int i = 0; i < sign.length(); i++)
		op[i + 1] = oper(num[i], num[i + 1], sign[i]);
	Max[0] = Min[0] = num[0];
	Max[1] = Min[1] = op[1];
	for (int i = 1; i < sign.length(); i++) {
		Max[i + 1] = max(oper(Max[i], num[i + 1], sign[i]), max(oper(Min[i - 1], op[i + 1], sign[i - 1]), oper(Max[i - 1], op[i + 1], sign[i - 1])));
		Min[i + 1] = min(oper(Min[i], num[i + 1], sign[i]), min(oper(Min[i - 1], op[i + 1], sign[i - 1]), oper(Max[i - 1], op[i + 1], sign[i - 1])));
	}
	return Max[N / 2];
}

int main(){
	int N;
	string data;

	cin >> N;
	cin >> data;

	cout << cal(data, N);
	return 0;
}