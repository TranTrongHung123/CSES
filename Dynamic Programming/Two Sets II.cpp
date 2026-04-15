#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MOD = 1e9 + 7;

ll dp[125251] = {1};

int main(){
    TranHungss();
    ll n; cin >> n;
    ll sum = n * (n + 1) / 2;
    if(sum % 2 != 0){
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    for(int i = 1; i < n; i++){
        for(int s = sum; s >= 1; s--){
            if(s - i >= 0){
                dp[s] += dp[s - i];
                dp[s] %= MOD;
            }
        }
    }
    cout << dp[sum] << endl;
}