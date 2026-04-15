#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

TranHungss(){
    FastIO();
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int &it : a) cin >> it;
    int res = 0, prefix = 0;
    map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i < n; i++){
        prefix += a[i];
        res += mp[prefix - x];
        ++mp[prefix];
    }
    cout << res << endl;
}