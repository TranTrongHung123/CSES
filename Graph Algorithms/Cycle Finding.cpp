#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int maxn = 2505;
 
int n, m;
vector<tuple<int, int, int>> edge;
 
void inp(){
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
}
 
void Bellman_Ford(){
    vector<int> par(n + 1, 0);
    vector<int> dis(n + 1, 0);
    dis[1] = 0;
    int st = -1;
    for(int i = 1; i <= n; i++){
        for(auto [u, v, w] : edge){
            if(dis[u] != 1e18 && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                par[v] = u;
                if(i == n){
                    st = v;
                    break;
                }
            }
        }
    }
    if(st == -1) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            st = par[st];
        }
        vector<int> cycle;
        int en = st;
        cycle.push_back(en); en = par[en];
        while(en != st){
            cycle.push_back(en);
            en = par[en];
        }
        cycle.push_back(en);
        reverse(begin(cycle), end(cycle));
        for(auto x : cycle) cout << x << " ";
    }
}
 
TranHungss(){
    FastIO();
    inp();
    Bellman_Ford();
}