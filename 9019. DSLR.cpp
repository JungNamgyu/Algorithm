#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector < vector<int> > cache;

int main(){
    int T;
    cin >> T;
    while(T--){
        int A, B, n;
        bool visit[10000] = {false};
        cache.resize(10000, vector<int> (2, 0));

        cin >> A >> B;
        queue <int> Q;
        Q.push(A);
        visit[A] = true;
        while(!Q.empty()){
            n = Q.front(); Q.pop();
            if(n == B) break;
 
            int D = (n*2) % 10000;
            int S = (n == 0 ? 9999 : n-1);
            int L = (n%1000) * 10 + n/1000;
            int R = (n%10)*1000 + (n/10);

            if(!visit[D]){ Q.push(D); visit[D] = true, cache[D][0] = n, cache[D][1] = 0;}
            if(!visit[S]){ Q.push(S); visit[S] = true, cache[S][0] = n, cache[S][1] = 1;}
            if(!visit[L]){ Q.push(L); visit[L] = true, cache[L][0] = n, cache[L][1] = 2;}
            if(!visit[R]){ Q.push(R); visit[R] = true, cache[R][0] = n, cache[R][1] = 3;}
        }
        while(!Q.empty()) Q.pop();

        string ANS;
        while(n != A){
            switch(cache[n][1]){
                case 0: ANS += 'D'; break;
                case 1: ANS += 'S'; break;
                case 2: ANS += 'L'; break;
                case 3: ANS += 'R'; break;
            }
            n = cache[n][0];
        }
        reverse(ANS.begin(), ANS.end());
        cout << ANS << endl;
    }

    return 0;
}