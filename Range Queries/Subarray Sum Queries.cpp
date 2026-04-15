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
const int maxn = 200002;

int n, m, a[maxn];

struct Node {
    int res, sum, pre, suf;
} seg[4 * maxn];

Node merge(Node x, Node y){
    Node tmp;
    tmp.sum = x.sum + y.sum;
    tmp.res = max({x.res, y.res, x.suf + y.pre});
    tmp.pre = max(x.pre, x.sum + y.pre);
    tmp.suf = max(y.suf, y.sum + x.suf);
    return tmp;
}

void build(int i, int l, int r){
    if(l == r){
        seg[i] = {a[l], a[l], a[l], a[l]};
    }
    else{
        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
    }
}

void update(int i, int l, int r, int pos, int val){
    if(l == r){
        seg[i] = {val, val, val, val};
    }
    else{
        int m = (l + r) >> 1;
        if(pos <= m){
            update(2 * i, l, m, pos, val);
        }
        else{
            update(2 * i + 1, m + 1, r, pos, val);
        }
        seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
    }
}

Node getAns(int i, int l, int r, int u, int v){
    if(l > v || r < u) return {-inf, 0, -inf, -inf};
    if(l >= u && r <= v) return seg[i];
    int m = (l + r) >> 1;
    auto s1 = getAns(2 * i, l, m, u, v);
    auto s2 = getAns(2 * i + 1, m + 1, r, u, v);
    return merge(s1, s2);
}

TranHungss(){
    FastIO();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(m--){
        int pos, val;
        cin >> pos >> val;
        update(1, 1, n, pos, val);
        cout << max(getAns(1, 1, n, 1, n).res, 0LL) << endl;
    }
    return (0 ^ 0);
}