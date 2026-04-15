#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define TranHungss() signed main()
#define back_insert back_inserter
#define __builtin_popcount __builtin_popcountll
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int maxn = 5005;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
 
string s;
int n, Hash1[maxn], Hash2[maxn], p1[maxn] = {1}, p2[maxn] = {1};
 
int getHash(int l, int r){
    int h1 = (Hash1[r] - Hash1[l - 1] * p1[r - l + 1] + mod1 * mod1) % mod1;
    int h2 = (Hash2[r] - Hash2[l - 1] * p2[r - l + 1] + mod2 * mod2) % mod2;
    return (h1 << 32) | h2;
}
 
TranHungss(){
    FastIO();
    cin >> s;
    n = s.size();
    s = " " + s;
    for(int i = 1; i <= n; i++){
        Hash1[i] = (Hash1[i - 1] * base1 + (int)s[i]) % mod1;
        Hash2[i] = (Hash2[i - 1] * base2 + (int)s[i]) % mod2;
        p1[i] = p1[i - 1] * base1 % mod1;
        p2[i] = p2[i - 1] * base2 % mod2;
    }
    unordered_set<int> st;
    int k; cin >> k;
    int maxLen = 0;
    while(k--){
        string dic; cin >> dic;
        int m = dic.size();
        maxLen = max(maxLen, m);
        int h1 = 0, h2 = 0;
        for(int i = 0; i < dic.size(); i++){
            h1 = (h1 * base1 + (int)dic[i]) % mod1;
            h2 = (h2 * base2 + (int)dic[i]) % mod2;
        }
        st.insert((h1 << 32) | h2);
    }
    int dp[maxn] = {1};
    for(int i = 1; i <= n; i++){
        for(int j = max(1LL, i - maxLen + 1); j <= i; j++){
            if(st.count(getHash(j, i))){
                dp[i] += dp[j - 1];
                dp[i] %= 1000000007;
            }
        }
    }
    cout << dp[n] << endl;
    return (0 ^ 0);
}
