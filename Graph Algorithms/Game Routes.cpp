#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005;
const int mod = 1e9 + 7;

int n, m, indegree[maxn], dp[maxn];
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
    queue<int> Q; 
    for(int u = 1; u <= n; u++){
        if(indegree[u] == 0){
            Q.push(u);
        }
    }
    dp[1] = 1;
    while(Q.size()){
        int u = Q.front(); Q.pop();
        for(int v : Ke[u]){
            --indegree[v];
            dp[v] = (dp[v] + dp[u]) % mod;
            if(indegree[v] == 0){
                Q.push(v);
            }
        }
    }
}

TranHungss(){
    FastIO();
    inp();
    Kahn();
    cout << dp[n] << endl;
}