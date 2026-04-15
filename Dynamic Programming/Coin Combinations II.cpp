
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int MOD = 1e9 + 7;

int main(){
    TranHungss();
    int n, x;
    cin >> n >> x;
    ll c[n];
    for(auto &x : c){
        cin >> x;
    }
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - c[i] >= 0){
                dp[j] += dp[j - c[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << endl; 
}