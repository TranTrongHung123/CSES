#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    int n;
    cin >> n;
    ll s1 = 1ll*n*(n+1)/2;
    ll s2 = 0;
    for(int i = 0; i < n-1; i++){
        ll x;
        cin >> x;
        s2 += x;
    }
    cout << s1 - s2 << endl;
}