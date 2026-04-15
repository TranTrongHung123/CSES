#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 100005;

int n, m;
set<int> Ke[maxn];

void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Ke[u].insert(v);
        Ke[v].insert(u);
    }
}

bool check(){
    for(int u = 1; u <= n; u++){
        if(Ke[u].size() & 1){
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
            auto v = *Ke[u].begin();
            stk.push(v);
            Ke[u].erase(v);
            Ke[v].erase(u);
        }
    }
    if(res.size() < m + 1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        reverse(begin(res), end(res));
        for(int x : res) cout << x << " ";
    }
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