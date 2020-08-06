#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct tree
{
    int value, le, ri;
};
int value;
vector<tree> PRE;

void setting(int v, int inx)
{
    if (PRE[v].value < PRE[inx].value)
    {
        if (PRE[inx].le == 0)
            PRE[inx].le = v;
        else
            setting(v, PRE[inx].le);
    }
    if (PRE[inx].value < PRE[v].value)
    {
        if (PRE[inx].ri == 0)
            PRE[inx].ri = v;
        else
            setting(v, PRE[inx].ri);
    }
}

void postorder(int x)
{
    if (PRE[x].le != 0)
        postorder(PRE[x].le);
    if (PRE[x].ri != 0)
        postorder(PRE[x].ri);
    cout << PRE[x].value << "\n";
}

int main()
{
    PRE.push_back(tree{0, 0, 0});
    for(int i=0;i<9;i++){
        cin >> value;
        PRE.push_back(tree{value, 0, 0});
    }
   // while (cin >> value)
     //   PRE.push_back(tree{value, 0, 0});
    for (int i = 2; i < PRE.size(); i++)
        setting(i, 1);
    postorder(1);
    return 0;
}