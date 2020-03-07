#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <bool> check;
vector < vector<int> > bus;
vector <int> v, cache, path;

int main() {
    int n, m, i, j;
    cin >> n >> m;
    bus.resize(n + 1);
    cache.resize(n + 1);
    v.resize(n + 1, 2e9);
    check.resize(n + 1, false);
    for (i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        bus[s].push_back(e); bus[s].push_back(v);
    }

    int S, E, Min, x;
    cin >> S >> E;
    v[S] = 0; Min = S;
    while (Min) {
        x = Min; check[x] = true;
        for (i = 0; i < bus[x].size(); i += 2) {
            if (v[bus[x][i]] > v[x] + bus[x][i + 1]) {
                cache[bus[x][i]] = x;
                v[bus[x][i]] = v[x] + bus[x][i + 1];
            }
        }
        for (Min = 0, i = 1; i <= n; i++)
            if (!check[i] && v[Min] > v[i]) Min = i;
    }
    for (int i = E; i != 0; i = cache[i])
        path.push_back(i);
    cout << v[E] << endl;
    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    return 0;
}