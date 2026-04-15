#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define TranHungss() signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int inf = (int)1e18;

TranHungss(){
    FastIO();
    int n; cin >> n;
    int a[n];
    for(int &x : a){
        cin >> x;
    }
    map<int, int> fre;
    int res = 1, left = 0;
    for(int right = 0; right < n; right++){
        ++fre[a[right]];
        while(fre[a[right]] >= 2){
            --fre[a[left++]];
        }
        res = max(res, right - left + 1);
    }
    cout << res << endl;
    return (0 ^ 0);
}