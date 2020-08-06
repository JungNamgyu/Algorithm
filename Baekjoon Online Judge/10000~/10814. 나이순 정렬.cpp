#include<cstdio>
#include<algorithm>
using namespace std;

struct Z {
	int age;
	char name[101];
	bool operator < (const Z &x) const {
		return age < x.age;
	}
}member[100000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%s", &member[i].age, &member[i].name);
	stable_sort(member, member + N);
	for (int i = 0; i < N; i++)
		printf("%d %s\n", member[i].age, member[i].name);
	return 0;
}