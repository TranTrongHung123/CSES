#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

TranHungss(){
    FastIO();
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] ^ a[i];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << (prefix[r] ^ prefix[l - 1]) << endl;
    }
}