
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
int main(){
    TranHungss();
    int n, x;
    cin >> n >> x;
    int c[n];
    for(auto &x : c){
        cin >> x;
    }
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - c[i] >= 0){
                dp[j] = min(dp[j], dp[j - c[i]] + 1);
            }
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
}
