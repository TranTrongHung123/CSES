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
const int maxn = 10000001;

int n, k, x, a, b, c, arr[maxn];

TranHungss(){
    FastIO();
    cin >> n >> k >> x >> a >> b >> c;
    arr[1] = x;
    for(int i = 2; i <= n; i++){
        arr[i] = (a * arr[i - 1] + b) % c;
    }
    int sum = 0;
    for(int i = 1; i <= k; i++){
        sum ^= arr[i];
    }
    int res = sum;
    for(int i = k + 1; i <= n; i++){
        sum ^= arr[i] ^ arr[i - k];
        res ^= sum;
    }
    cout << res << endl;
    return (0 ^ 0);
}