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

const int BASE1 = 311;
const int BASE2 = 997;
const int INF = (int)1e18;

 _nO_Op_ {
    FastIO();
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for(int &x : a){
        cin >> x;
    }
    int b[m];
    for(int &x : b){
        cin >> x;
    }
    sort(a, a + n);
    sort(b, b + m);
    int res = 0, i = 0, j = 0;
    while(i < n && j < m){
        if(b[j] >= a[i] - k && b[j] <= a[i] + k){
            ++res; ++i; ++j;
        }
        else if(b[j] < a[i] - k){
            ++j;
        }
        else{
            ++i;
        }
    }
    cout << res << endl;
    return (0 ^ 0);
}