#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005;
const int INF = 1e18;

int n, m;
vector<pair<int, int>> Ke[maxn];

void inp(){
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        Ke[u].push_back({v, w});
    }
}

void Dijkstra(){
    vector<vector<int>> dis(n + 1, vector<int>(2, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    dis[1][0] = 0;
    pq.push({dis[1][0], 1, 0});
    while(pq.size()){
        auto [d, u, used] = pq.top(); pq.pop();
        if(d > dis[u][used]) continue;
        for(auto [v, w] : Ke[u]){
            if(dis[v][used] > dis[u][used] + w){
                dis[v][used] = dis[u][used] + w;
                pq.push({dis[v][used], v, used});
            }
            if(used == 0 && dis[v][1] > dis[u][0] + w / 2){
                dis[v][1] = dis[u][0] + w / 2;
                pq.push({dis[v][1], v, 1});
            }
        }
    }
    cout << dis[n][1] << endl;
}

TranHungss(){
    FastIO();
    inp();
    Dijkstra();
}