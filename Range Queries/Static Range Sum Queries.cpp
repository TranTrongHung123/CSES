#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
ll a[1000000], prefix[1000000];
 
int main(){
    TranHungss();
	ll n, q;
	cin >> n >> q;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(ll i = 1; i <= n; i++){
		prefix[i] = prefix[i-1] + a[i];
	}
	while(q--){
		ll l, r;
		cin >> l >> r;
		if(l == 1){
			cout << prefix[r] << endl;
		}
		else{
			cout << prefix[r] - prefix[l-1] << endl;
		}
	}
}
