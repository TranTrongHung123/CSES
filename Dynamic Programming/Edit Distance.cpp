#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

signed main(){
    TranHungss();
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = " " + s1; s2 = " " + s2;
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = i + j;
            }
            else if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    cout << dp[n][m] << endl;
}