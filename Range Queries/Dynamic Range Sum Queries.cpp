#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 200002;

int n, m, a[maxn], IT[4 * maxn];

void built(int i, int l, int r){
    if(l == r){
        IT[i] = a[l];
    }
    else{
        int m = (l + r) >> 1;
        built(2 * i, l, m);
        built(2 * i + 1, m + 1, r);
        IT[i] = IT[2 * i] + IT[2 * i + 1];
    }
}

void update(int i, int l, int r, int pos, int val){
    if(l == r){
        IT[i] = val;
    }
    else{
        int m = (l + r) >> 1;
        if(pos <= m){
            update(2 * i, l, m, pos, val);
        } 
        else{
            update(2 * i + 1, m + 1, r, pos, val);
        }
        IT[i] = IT[2 * i] + IT[2 * i + 1];
    }
}

int getSum(int i, int l, int r, int u, int v){
    if(l > v || r < u) return 0;
    if(l >= u && r <= v) return IT[i];
    int m = (l + r) >> 1;
    int s1 = getSum(2 * i, l, m, u, v);
    int s2 = getSum(2 * i + 1, m + 1, r, u, v);
    return s1 + s2;
}

TranHungss(){
    FastIO();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    built(1, 1, n);
    while(m--){
        int x, u, v;
        cin >> x >> u >> v;
        if(x == 1){
            update(1, 1, n, u, v);
        }
        else{
            cout << getSum(1, 1, n, u, v) << endl;
        }
    }
}