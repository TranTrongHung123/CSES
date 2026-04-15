#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 505;

int n, m, q, dis[maxn][maxn];

void init(){
    for(int i = 1; i <= maxn; i++){
        for(int j = 1; j <= maxn; j++){
            if(i == j){
                dis[i][j] = 0;
            }
            else{
                dis[i][j] = 1e18;
            }
        }
    }
}

void inp(){
    init();
    cin >> n >> m >> q;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min({dis[u][v], dis[v][u], w});
    }
}

void Floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

TranHungss(){
    FastIO();
    inp();
    Floyd();
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << (dis[x][y] == 1e18 ? -1 : dis[x][y]) << endl;
    }
}