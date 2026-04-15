#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 1000001;

int dp[maxn];

void init(){
    for(int i = 1; i <= 9; i++){
        dp[i] = 1;
    }
    for(int i = 10; i <= 1000000; i++){
        dp[i] = 1e9;
        string s = to_string(i);
        for(int j = 1; j <= 9; j++){
            for(char c : s){
                if(c == j + '0'){
                    dp[i] = min(dp[i],  dp[i-j] + 1);
                }
            }
        }
    }
}

int main(){
    TranHungss();
    init();
    int n; cin >> n;
    cout << dp[n] << endl;
}