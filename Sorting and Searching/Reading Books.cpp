#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define _nO_Op_ signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = (int)1e18;

 _nO_Op_ {
    FastIO();
    int n; cin >> n;
    int a[n];
    for(int &x : a){
        cin >> x;
    }
    int sum = accumulate(a, a + n, 0LL);
    cout << max(sum, 2 * *max_element(a, a + n));
    return (0 ^ 0);
}