#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool check(ll t, ll s, ll a[], ll n){
    ll res = 0;
    for(ll i = 0; i < n; i++){
        res += t / a[i];
    }
    if(res >= s){
        return true;
    }
    return false;
}

ll binary_search_on_anwer(ll left, ll right, ll s, ll a[], ll n){
    ll res = 0;
    while(left <= right){
        ll mid = (left + right) / 2;
        if(check(mid, s, a, n)){
            res = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return res;
}

int main(void){
    TranHungss();
    ll n, s;
    cin >> n >> s;
    ll a[n];
    for(auto &x : a){
        cin >> x;
    }
    ll left = 1;
    ll right = s * (*min_element(a, a + n));
    cout << binary_search_on_anwer(left, right, s, a, n) << endl;
}