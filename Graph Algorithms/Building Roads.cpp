#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100001;

int n, m, visited[maxn];
vector<int> Ke[maxn];

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        Ke[x].push_back(y);
        Ke[y].push_back(x);
    }
}

int tplt = 1;
vector<int> res[maxn];

void DFS(int u){
    res[tplt].push_back(u);
    visited[u] = 1;
    for(int v : Ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}

int main(){
    TranHungss();
    input();
    for(int u = 1; u <= n; u++){
        if(!visited[u]){
            DFS(u);
            ++tplt;
        }
    }
    cout << tplt - 2 << endl;
    for(int i = 1; i < (tplt - 1); i++){
        cout << res[i][0] << " " << res[i+1][0] << endl;
    }
}