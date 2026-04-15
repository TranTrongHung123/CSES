#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

TranHungss(){
    FastIO();
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> dp(begin(a), end(a));
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i], dp[i - 1] + a[i]);
    }
    cout << *max_element(begin(dp), end(dp)) << endl;
}