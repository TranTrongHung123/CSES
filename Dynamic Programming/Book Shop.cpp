#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    int n, x;
    cin >> n >> x;
    pair<int,int> a[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].second;
    }
    int dp[x+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= 1; j--){
            if(j - a[i].first >= 0){
                dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
            }
        }
    }
    cout << dp[x] << endl;
}

// #include <bits/stdc++.h>
// #define ll long long
// #define endl "\n"
// #define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// using namespace std;
 
// int main(){
//     TranHungss();
//     int n, x;
//     cin >> n >> x;
//     pair<int,int> a[n+1];
//     for(int i = 1; i <= n; i++){
//         cin >> a[i].first;
//     }
//     for(int i = 1; i <= n; i++){
//         cin >> a[i].second;
//     }
//     int dp[n+1][x+1];
//     memset(dp, 0, sizeof(dp));
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= x; j++){
//             dp[i][j] = dp[i-1][j];
//             if(j - a[i].first >= 0){
//                 dp[i][j] = max(dp[i][j], dp[i-1][j-a[i].first] + a[i].second);
//             }
//         }
//     }
//     cout << dp[n][x] << endl;
// }
