#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 1001;
const int MOD = 1e9 + 7;

int dp[maxn][maxn];

int main(){
    TranHungss();
    int n; cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
            if(c == '.'){
                if(i == 1 && j == 1){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] += dp[i-1][j] + dp[i][j-1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[n][n] << endl;
}