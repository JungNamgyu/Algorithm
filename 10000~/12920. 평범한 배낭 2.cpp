#include <iostream>
#include <vector>
using namespace std;

struct object
{
    int V, C;
};

int N, M;
vector<object> O;
vector<int> Cache;

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        int v, c, k;
        cin >> v >> c >> k;
        for(int i=1;k>0;i<<=1){
            int inx = min(i, k);
            O.push_back(object{v*inx, c*inx});
            k -= inx;
        }
    }

    int sz = O.size();
    Cache.resize(M + 1, 0);
    for (int i = 0; i < sz; i++)
    {
        for (int j = M; j >= O[i].V; j--)
            Cache[j] = max(Cache[j], Cache[j - O[i].V] + O[i].C);
    }
    cout << Cache[M] << endl;
    return 0;
}