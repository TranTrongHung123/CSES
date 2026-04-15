#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    int n; cin >> n;
    int a[n];
    for(auto &x : a) cin >> x;
    vector<int> res;
    res.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] > res.back()){
            res.push_back(a[i]);
        }
        else{
            auto it = lower_bound(begin(res), end(res), a[i]);
            res[(it - res.begin())] = a[i];
        }
    }
    cout << res.size() << endl;
}