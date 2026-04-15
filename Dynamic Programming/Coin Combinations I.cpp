
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
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - c[j] >= 0){
                dp[i] += dp[i - c[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << endl; 
}