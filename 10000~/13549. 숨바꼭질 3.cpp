#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Z
{
    int cost, inx;
    bool operator()(Z x, Z y)
    {
        return x.cost > y.cost;
    }
};

Z x;
int n, k;
vector<int> Cache;
priority_queue<Z, vector<Z>, Z> pq;

int main()
{
    cin >> n >> k;
    Cache.resize(2 * k, 2e9);
    pq.push({0, n});
    if(n > k)
        cout << n-k << endl;
    else{
    while (true)
    {
        x = pq.top();
        pq.pop();
        Cache[x.inx] = x.cost;
        if (x.inx == k)
            break;
        if (x.inx * 2 < 2 * k)
            if (Cache[x.inx * 2] > x.cost)
                pq.push(Z{x.cost, x.inx * 2});
        if (x.inx - 1 >= 0)
            if (Cache[x.inx - 1] > x.cost + 1)
                pq.push(Z{x.cost + 1, x.inx - 1});
        if (x.inx + 1 < 2 * k)
            if (Cache[x.inx + 1] > x.cost + 1)
                pq.push(Z{x.cost + 1, x.inx + 1});
    }
    cout << x.cost << endl;
    }
    return 0;
}