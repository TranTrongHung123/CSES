#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int mod = 1000000007;

ll luy_thua(ll n){
    ll res = 1, a = 2;
    while(n){
        if(n % 2 == 1){
            res *= a;
            res %= mod;
        }
        n /= 2;
        a *= a;
        a %= mod;
    }
    return res;
}

int main(){
    TranHungss();
    ll n;
    cin >> n;
    cout << luy_thua(n) << endl;
}