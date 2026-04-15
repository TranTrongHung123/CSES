#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int maxn = 1000001;
 
int n;
set<int> Ke[maxn];
 
void inp(){
    cin >> n;
    for(int u = 0; u < (1 << (n - 1)); u++){
        int v = (u << 1) % (1 << (n - 1));
        Ke[u].insert(v);
        Ke[u].insert(v | 1);
    }
}
 
void Euler(){
    vector<int> res;
    stack<int> stk; stk.push(0);
    while(stk.size()){
        int u = stk.top();
        if(Ke[u].size()){
            int v = *Ke[u].begin();
            stk.push(v);
            Ke[u].erase(v);
        }
        else{
            res.push_back(u & 1);
            stk.pop();
        }
    }
    for(int i = 0; i < n - 2; i++) res.push_back(0);
    for(int x : res) cout << x;
}
 
TranHungss(){
    FastIO();
    inp();
    if(n == 1){
        cout << "10" << endl;
        return 0;
    }
    Euler();
}