#pragma warning(disable:4996)

#include<cstdio>
#include<cstring>

int main() {
	int M, S = 0;
	scanf("%d", &M);
	while (M--) {
		char command[7];
		scanf("%s", command);
		if (strcmp(command, "all") == 0) S |= ~1;
		else if (strcmp(command, "empty") == 0) S &= 1;
		else {
			int x;
			scanf("%d", &x);
			if (strcmp(command, "add") == 0)
				S |= (1 << x);
			if (strcmp(command, "remove") == 0)
				S &= ~(1 << x);
			if (strcmp(command, "check") == 0)
				printf("%d\n", (S & (1 << x) ? 1 : 0));
			if (strcmp(command, "toggle") == 0)
				S ^= (1 << x);
		}
	}
}