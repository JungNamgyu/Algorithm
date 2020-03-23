#include <iostream>
using namespace std;

struct Z
{
    int time, money;
} Trip[101][3];
int N, K, Max, Cache[101][100001], Sum[101];

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> Trip[i][0].time >> Trip[i][0].money >> Trip[i][1].time >> Trip[i][1].money;
    
    Sum[0] = min(Trip[0][0].time, Trip[0][1].time);
    for (int i = 1; i< N;i++)
        Sum[i] = Sum[i-1] + min(Trip[i][0].time, Trip[i][1].time);
    
    for (int i = Trip[0][0].time; i <= K; i++)
        Cache[0][i] = max(Cache[0][i], Trip[0][0].money);
    for (int i = Trip[0][1].time; i <= K; i++)
        Cache[0][i] = max(Cache[0][i], Trip[0][1].money);
    
    for (int i = 1; i < N; i++)
    {
        for (int j = Sum[i-1] + Trip[i][0].time; j <= K; j++)
            Cache[i][j] = max(Cache[i][j], Cache[i-1][j-Trip[i][0].time] + Trip[i][0].money);
        for (int j = Sum[i-1] + Trip[i][1].time; j <= K; j++)
            Cache[i][j] = max(Cache[i][j], Cache[i-1][j-Trip[i][1].time] + Trip[i][1].money);
    }
    cout << Cache[N-1][K];
}