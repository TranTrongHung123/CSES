#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    TranHungss();
    int n;
    cin >> n;
    ll dp[n + 1] = {1};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if((i - j) >= 0){
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
}