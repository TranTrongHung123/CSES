#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int mod = 1000000007;

ll Luy_Thua(ll a, ll b){
    if(b == 0) return 1;
    ll tmp = Luy_Thua(a, b/2);
    if(b % 2 == 1){
        return ((((tmp % mod) * (tmp % mod)) % mod) * (a % mod)) % mod;
    }
    else{
        return ((tmp % mod) * (tmp % mod)) % mod;
    }
}

int main(void){
    TranHungss();
    int Q;
    cin >> Q;
    while(Q--){
        ll a, b;
        cin >> a >> b;
        if(a == 0 and b == 0) cout << "1" << endl;
        else{
            cout << Luy_Thua(a, b) << endl;
        }
    }
}