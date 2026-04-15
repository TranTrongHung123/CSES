#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005;

int n, m, cnt = 1, scc = 0;
int num[maxn], low[maxn], deleted[maxn];
vector<int> Ke[maxn];
stack<int> stk;
vector<int> res;

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        Ke[x].push_back(y);
    }
}

void DFS(int u){
    stk.push(u);
    num[u] = low[u] = cnt++;
    for(int v : Ke[u]){
        if(deleted[v]) continue;
        if(!num[v]){
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], num[v]);
        }
    }
    if(num[u] == low[u]){
        res.push_back(u);
        ++scc;
        int v;
        do{
            v = stk.top();
            stk.pop();
            deleted[v] = 1;
        }while(v != u);
    }
}

int main(){
    TranHungss();
    input();
    for(int u = 1; u <= n; u++){
        if(!num[u]){
            DFS(u);
        }
    }
    if(scc > 1){
        cout << "NO" << endl;
        cout << res[0] << " " << res[1] << endl;
    }
    else{
        cout << "YES" << endl;
    }
}