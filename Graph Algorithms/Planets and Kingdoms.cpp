#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005;

int n, m, mark[maxn], del[maxn], low[maxn], num[maxn], id = 1, scc = 0;
vector<int> Ke[maxn];
stack<int> stk;

void inp(){
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        Ke[u].push_back(v);
    }
}

void DFS(int u){
    low[u] = num[u] = id++;
    stk.push(u);
    for(int v : Ke[u]){
        if(del[v]) continue;
        if(num[v] == 0){
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], num[v]);
        }
    }
    if(low[u] == num[u]){
        ++scc;
        while(stk.size() && stk.top() != u){
            mark[stk.top()] = scc;
            del[stk.top()] = 1;
            stk.pop();
        }
        mark[u] = scc;
        del[u] = 1;
        stk.pop();
    }
}

TranHungss(){
    FastIO();
    inp();
    for(int u = 1; u <= n; u++){
        if(num[u] == 0){
            DFS(u);
        }
    }
    cout << scc << endl;
    for(int u = 1; u <= n; u++){
        cout << mark[u] << " ";
    }
}