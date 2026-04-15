#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005;
const ll INF = 1e18;

int n, m;
int visited[maxn];
vector<pair<int, int>> Ke[maxn];

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        Ke[x].push_back({y, w});
    }
}

void Dijkstra(int root){
    vector<ll> d(n + 1, INF);
    d[root] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({d[root], root});
    while(!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        int u = tmp.second;
        if(visited[u]) continue;
        visited[u] = 1;
        for(auto x : Ke[u]){
            int v = x.first;
            int w = x.second;
            if(d[v] > (d[u] + w)){
                d[v] = (ll)(d[u] + w);
                pq.push({d[v], v});
            }
        }
    }
    for(int u = 1; u <= n; u++){
        cout << d[u] << " ";
    }
}

int main(){
    TranHungss();
    input();
    Dijkstra(1);
}