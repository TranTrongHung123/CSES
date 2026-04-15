#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    int n;
    cin >> n;
    int a[n];
    for(auto &x : a){
        cin >> x;
    }
    ll res = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1]){
            int d = (a[i-1] - a[i]);
            res += 1ll * d;
            a[i] = a[i-1];
        }
    }
    cout << res << endl;
}