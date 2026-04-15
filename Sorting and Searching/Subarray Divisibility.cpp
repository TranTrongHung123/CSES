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
    int a[n];
    for(int &x : a) cin >> x;
    int res = 0, prefix = 0;
    map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i < n; i++){
        prefix = ((prefix + a[i]) % n + n) % n;
        res += mp[prefix];
        ++mp[prefix];
    }
    cout << res << endl;
}