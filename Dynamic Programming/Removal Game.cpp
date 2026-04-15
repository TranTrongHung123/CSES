#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

signed main(){
    TranHungss();
    int n; cin >> n;
    int a[n];
    for(auto &x : a) cin >> x;
    int dp[n][n], sum = 0;
    for(int i = n - 1; i >= 0; i--){
        sum += a[i];
        for(int j = i; j < n; j++){
            if(i == j){
                dp[i][j] = a[i];
            }
            else{
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
            }
        }
    }
    cout << (sum + dp[0][n-1]) / 2 << endl;
}