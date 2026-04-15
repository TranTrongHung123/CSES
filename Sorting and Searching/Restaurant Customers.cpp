#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define endl "\n"
#define int long long
#define double long double
#define _nO_Op_ signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int BASE1 = 311;
const int BASE2 = 997;
const int INF = (int)1e18;

_nO_Op_ {
    FastIO();
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    vector<int> compress;
    for (auto &[x, y] : a) {
        cin >> x >> y;
        compress.push_back(x);
        compress.push_back(y);
    }
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    for (auto &[x, y] : a) {
        x = lower_bound(compress.begin(), compress.end(), x) - compress.begin();
        y = lower_bound(compress.begin(), compress.end(), y) - compress.begin();
    }
    int m = compress.size();
    vector<int> diff(m + 2, 0), prefix(m + 2, 0);
    for (int i = 0; i < n; i++) {
        diff[a[i].first]++;
        diff[a[i].second + 1]--;
    }
    prefix[0] = diff[0];
    for (int i = 1; i < m; i++){
        prefix[i] = prefix[i - 1] + diff[i];
    }
    cout << *max_element(prefix.begin(), prefix.end());
    return 0;
}