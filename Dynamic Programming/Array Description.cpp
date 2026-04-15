#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    TranHungss();
    int n, m;
    cin >> n >> m;
    int a[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    if(a[1] != 0){
        dp[1][a[1]] = 1;
    }
    else{
        for(int j = 1; j <= m; j++){
            dp[1][j] = 1;
        }
    }
    for(int i = 2; i <= n; i++){
        if(a[i] != 0){
            dp[i][a[i]] += (dp[i - 1][a[i]] + dp[i - 1][a[i] - 1] + dp[i - 1][a[i] + 1]);
            dp[i][a[i]] %= MOD;
        }
        else{
            for(int j = 1; j <= m; j++){
                dp[i][j] += (dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]);
                dp[i][j] %= MOD;
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= m; i++){
        res += dp[n][i];
        res %= MOD;
    }
    cout << res << endl;
}