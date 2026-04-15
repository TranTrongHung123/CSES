#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define _nO_Op_ signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = (int)1e18;

bool cmp(pair<int, int> x, pair<int, int> y){
    return x.first < y.first;
}

 _nO_Op_ {
    FastIO();
    int n; cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n, cmp);
    int res = 1;
    for(int i = 1; i < n; i++){
        if(a[i].second < a[i - 1].second){
            ++res;
        }
    }
    cout << res << endl;
    return (0 ^ 0);
}