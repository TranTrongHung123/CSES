#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define TranHungss() signed main()
#define Faster(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 2000002;
const int MOD = 1e9 + 7;

int PowMod(int a, int b){
    int res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

int InverMod(int a){
    return PowMod(a, MOD - 2);
}

int f[maxn];

void init(){
    f[0] = f[1] = 1;
    for(int i = 2; i <= 2000000; i++){
        f[i] = i * f[i - 1];
        f[i] %= MOD;
    }
}

TranHungss(){
    Faster();
    init();
    int n, m;
    cin >> n >> m;
    cout << f[m + n - 1] % MOD * InverMod(f[m] * f[n - 1] % MOD) % MOD;
}