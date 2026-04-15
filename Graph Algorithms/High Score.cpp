#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100000;

int n, m, vis1[maxn], vis2[maxn];
vector<int> Ke1[maxn], Ke2[maxn];
vector<tuple<int, int, int>> edge;

void DFS1(int u){
    vis1[u] = 1;
    for(int v : Ke1[u]){
        if(vis1[v] == 0){
            DFS1(v);
        }
    }
}

void DFS2(int u){
    vis2[u] = 1;
    for(int v : Ke2[u]){
        if(vis2[v] == 0){
            DFS2(v);
        }
    }
}

void inp(){
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, -w});
        Ke1[u].push_back(v);
        Ke2[v].push_back(u);
    }
}

void Bellman_Ford(){
    DFS1(1); DFS2(n);
    vector<int> dis(n + 1, 1e18);
    dis[1] = 0;
    for(int i = 1; i <= n; i++){
        for(auto [u, v, w] : edge){
            if(dis[u] != 1e18 && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(i == n && vis1[v] && vis2[v]){
                    cout << "-1" << endl;
                    return;
                }
            }
        }
    }
    cout << -dis[n] << endl;
}

TranHungss(){
    FastIO();
    inp();
    Bellman_Ford();
}