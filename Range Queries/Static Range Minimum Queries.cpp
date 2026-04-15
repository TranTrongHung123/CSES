#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 200002;

int n, m, a[maxn], spt[22][maxn];

void Sparse_Table(){
    for(int j = 1; j <= n; j++){
        spt[0][j] = a[j];
    }
    for(int i = 1; i <= __lg(n); i++){
        for(int j = 1; j <= n - (1 << i) + 1; j++){
            spt[i][j] = min(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int getMin(int l, int r){
    int k = __lg(r - l + 1);
    return min(spt[k][l], spt[k][r - (1 << k) + 1]);
}

TranHungss(){
    FastIO();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    Sparse_Table();
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << getMin(l, r) << endl;
    }
}