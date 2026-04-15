#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005;

int n, m, indegree[maxn];
vector<int> Ke[maxn];

void inp(){
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        Ke[u].push_back(v);
        ++indegree[v];
    }
}

void Kahn(){
    vector<int> dis(n + 1, -1e18);
    vector<int> par(n + 1, 0);
    queue<int> Q;
    dis[1] = 1;
    for(int u = 1; u <= n; u++){
        if(indegree[u] == 0){
            Q.push(u);
        }
    }
    while(Q.size()){
        int u = Q.front(); Q.pop();
        for(int v : Ke[u]){
            --indegree[v];
            if(dis[u] + 1 > dis[v]){
                dis[v] = dis[u] + 1;
                par[v] = u;
            }
            if(indegree[v] == 0){
                Q.push(v);
            }
        }
    }
    if(dis[n] < 0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << dis[n] << endl;
        vector<int> path;
        while(n != 1){
            path.push_back(n);
            n = par[n];
        }
        path.push_back(n);
        reverse(begin(path), end(path));
        for(int x : path) cout << x << " ";
    }
}

TranHungss(){
    FastIO();
    inp();
    Kahn();
}