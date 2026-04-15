#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005;

int n, m, color[maxn];
vector<int> Ke[maxn];

void inp(){
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        Ke[u].push_back(v);
        Ke[v].push_back(u);
    }
}

bool check(int root){
    queue<int> Q; Q.push(root);
    color[root] = 1;
    while(Q.size()){
        int u = Q.front(); Q.pop();
        for(int v : Ke[u]){
            if(color[v] == 0){
                color[v] = (color[u] == 1 ? 2 : 1);
                Q.push(v);
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}

TranHungss(){
    FastIO();
    inp();
    bool ok = true;
    for(int u = 1; u <= n; u++){
        if(color[u] == 0){
            if(check(u) == false){
                ok = false;
                break;
            }
        }
    }
    if(ok){
        for(int i = 1; i <= n; i++){
            cout << color[i] << " ";
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}