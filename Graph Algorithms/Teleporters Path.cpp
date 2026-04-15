#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005;

int n, m, indegree[maxn], outdegree[maxn];
set<int> Ke[maxn];

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Ke[u].insert(v);
        ++indegree[v];
        ++outdegree[u];
    }
}

bool check(){
    if(outdegree[1] - indegree[1] != 1) return false;
    if(indegree[n] - outdegree[n] != 1) return false;
    for(int u = 2; u <= n - 1; u++){
        if(indegree[u] != outdegree[u]){
            return false;
        }
    }
    return true;
}

void Euler_Cycle(){
    vector<int> res;
    stack<int> stk;
    stk.push(1);
    while(stk.size()){
        int u = stk.top();
        if(Ke[u].size() == 0){
            res.push_back(u);
            stk.pop();
        }
        else{
            auto it = *Ke[u].begin();
            Ke[u].erase(it);
            stk.push(it);
        }
    }
    if(res.size() < m + 1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    reverse(begin(res), end(res));
    for(auto x : res) cout << x << " ";
}

TranHungss(){
    FastIO();
    inp();
    if(check()){
        Euler_Cycle();
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}