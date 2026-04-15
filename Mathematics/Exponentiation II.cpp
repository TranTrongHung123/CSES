#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int mod = 1000000007;

ll luy_thua(ll a, ll n, ll x){
    ll res = 1;
    while(n){
        if(n % 2 == 1){
            res *= a;
            res %= x;
        }
        n /= 2;
        a *= a;
        a %= x;
    }
    return res;
}

int main(){
    TranHungss();
    int TC;
    cin >> TC;
    while(TC--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll tmp = luy_thua(b, c, mod - 1);
        if(a == 0 and tmp == 0){
            cout << 1 << endl;
        }
        else{
            cout << luy_thua(a, tmp, mod) << endl;
        }
    }
}