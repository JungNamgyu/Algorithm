#include<iostream>
#include<vector>
using namespace std;

int N;
vector < pair<int, int> > Tree;

void preorder(int x){
    cout << (char)(x+'A');
    if(Tree[x].first != -1) preorder(Tree[x].first);
    if(Tree[x].second != -1) preorder(Tree[x].second);
}
void inorder(int x){
    if(Tree[x].first != -1) inorder(Tree[x].first);
    cout << (char)(x+'A');
    if(Tree[x].second != -1) inorder(Tree[x].second);
}
void postorder(int x){
    if(Tree[x].first != -1) postorder(Tree[x].first);
    if(Tree[x].second != -1) postorder(Tree[x].second);
    cout << (char)(x+'A');
}
int main(){
    cin >> N;
    Tree.resize(N);
    for(int i=0;i<N;i++){
        char node, left, right;
        cin >> node >> left >> right;
        Tree[node-'A'].first = (left == '.' ? -1 : left-'A');
        Tree[node-'A'].second = (right == '.' ? -1 : right-'A');
    }
    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    return 0;
}