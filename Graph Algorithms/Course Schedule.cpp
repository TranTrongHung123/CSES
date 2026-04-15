#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100001;

int n, m;
int deg[maxn];
vector<int> Ke[maxn];

void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        Ke[x].push_back(y);
        ++deg[y];
    }
}

void Kahn(){
    vector<int> topo;
    queue<int> q;
    for(int u = 1; u <= n; u++){
        if(deg[u] == 0){
            q.push(u);
        }
    }
    while(!q.empty()){
        int v = q.front(); q.pop();
        topo.push_back(v);
        for(auto x : Ke[v]){
            --deg[x];
            if(deg[x] == 0){
                q.push(x);
            }
        }
    }
    if(topo.size() == n){
        for(auto it : topo){
            cout << it << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}

int main(){
    TranHungss();
    input();
    Kahn();
}