#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 255*255

int n;
int t[255][2];
int dp[255][MAX+1][2];

int main(){
	scanf("%d", &n);
	memset(dp, MAX + 1, sizeof(dp));
	
    	for(int i=0;i<n;i++)
		scanf("%d%d", &t[i][0], &t[i][1]);

	dp[0][MAX/2 - t[0][0]][0] = t[0][0];
	dp[0][MAX/2 - t[0][0]][1] = 0;
	dp[0][MAX/2 + t[0][1]][0] = 0;
	dp[0][MAX/2 + t[0][1]][1] = t[0][1];
	
	for(int x = 1; x < n; x++){
		for(int c = 0; c < MAX + 1; c++){
			if(!(dp[x-1][c][0] == MAX + 1 && dp[x-1][c][1] == MAX + 1)){
				if(c-t[x][0] >= 0){
					if(max(dp[x][c-t[x][0]][0], dp[x][c-t[x][0]][1]) > max(dp[x - 1][c][0] + t[x][0], dp[x-1][c][1])){
						dp[x][c-t[x][0]][0] = dp[x-1][c][0] + t[x][0];
						dp[x][c-t[x][0]][1] = dp[x-1][c][1];
					}
				}
				if(c+t[x][1] <= MAX){
					if(max(dp[x][c+t[x][1]][0], dp[x][c+t[x][1]][1]) > max(dp[x - 1][c][0], dp[x-1][c][1] + t[x][1])){
						dp[x][c+t[x][1]][0] = dp[x-1][c][0];
						dp[x][c+t[x][1]][1] = dp[x-1][c][1] + t[x][1];
					}
				}
			}
		}
	}
	int Min = MAX + 1;
	for(int c = 0; c < MAX + 1; c++)
		Min = min(Min, max(dp[n-1][c][0], dp[n-1][c][1]));
	printf("%d",Min);			
	return 0;
}