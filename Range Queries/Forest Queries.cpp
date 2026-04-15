#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
ll prefix[1001][1001], a[1001][1001];
char b[1001][1001];
 
int main(){
    TranHungss();
	ll n, q;
	cin >> n >> q;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			cin >> b[i][j];
			if(b[i][j] == '*'){
				a[i][j] = 1;
			}
			else{
				a[i][j] = 0;
			}
		}
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			prefix[i][j] = a[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1]; 
		}
	}
	while(q--){
		ll h1, c1, h2, c2;
		cin >> h1 >> c1 >> h2 >> c2;
		cout << prefix[h2][c2] - prefix[h2][c1-1] - prefix[h1-1][c2] + prefix[h1-1][c1-1] << endl;
	}	
}