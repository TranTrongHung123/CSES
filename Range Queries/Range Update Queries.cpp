#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define TranHungss() signed main()
#define __builtin_popcount __builtin_popcountll
#define join(x, y, z); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 200002;

int n, q, a[maxn], IT[4 * maxn], lazy[4 * maxn];

void build(int i, int l, int r){
    if(l == r){
        IT[i] = a[l];
    }
    else{
        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        IT[i] = IT[2 * i] + IT[2 * i + 1];
    }
}

void push(int i, int l, int r){
    if(lazy[i] == 0) return;
    int m = (l + r) >> 1;
    IT[2 * i] += (m - l + 1) * lazy[i];
    lazy[2 * i] += lazy[i];
    IT[2 * i + 1] += (r - m) * lazy[i];
    lazy[2 * i + 1] += lazy[i];
    lazy[i] = 0;
}

void update(int i, int l, int r, int u, int v, int val){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        IT[i] += (r - l + 1) * val;
        lazy[i] += val;
        return;
    }
    push(i, l, r);
    int m = (l + r) >> 1;
    update(2 * i, l, m, u, v, val);
    update(2 * i + 1, m + 1, r, u, v, val);
    IT[i] = IT[2 * i] + IT[2 * i + 1];
}

int getAns(int i, int l, int r, int k){
    if(l == r) return IT[i];
    push(i, l, r);
    int m = (l + r) >> 1;
    if(k <= m){
        return getAns(2 * i, l, m, k);
    }
    else{
        return getAns(2 * i + 1, m + 1, r, k);
    }
}

TranHungss(){
    FastIO();
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int u, v, val;
            cin >> u >> v >> val;
            update(1, 1, n, u, v, val);
        }
        else{
            int k; cin >> k;
            cout << getAns(1, 1, n, k) << endl;
        }
    }
    return (0 ^ 0);
}