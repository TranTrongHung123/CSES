#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define uint unsigned long long
#define FastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 1000005;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

string s, t;
int n, m;
int HashS1[maxn], HashS2[maxn], ps1[maxn], ps2[maxn];

pair<int, int> getHashS(int l, int r){
    int h1 = (HashS1[r] - HashS1[l - 1] * ps1[r - l + 1] + mod1 * mod1) % mod1;
    int h2 = (HashS2[r] - HashS2[l - 1] * ps2[r - l + 1] + mod2 * mod2) % mod2;
    return {h1, h2};
}

signed main(){
    FastIO();
    cin >> s >> t;
    n = s.size(); m = t.size();
    s = " " + s; t = " " + t;
    ps1[0] = ps2[0] = 1;
    for(int i = 1; i <= n; i++){
        HashS1[i] = (HashS1[i - 1] * base1 + (int)s[i]) % mod1;
        HashS2[i] = (HashS2[i - 1] * base2 + (int)s[i]) % mod2;
        ps1[i] = ps1[i - 1] * base1 % mod1;
        ps2[i] = ps2[i - 1] * base2 % mod2;
    }
    pair<int, int> hashT = {0, 0};
    for(int i = 1; i <= m; i++){
        hashT.first = (hashT.first * base1 + (int)t[i]) % mod1;
        hashT.second = (hashT.second * base2 + (int)t[i]) % mod2;
    }
    int res = 0;
    for(int i = m; i <= n; i++){
        if(getHashS(i - m + 1, i) == hashT){
            res++;
        }
    }
    cout << res << endl;
}