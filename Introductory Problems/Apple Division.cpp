#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, a[100], X[100];
ll res = LLONG_MAX;

void Try(int i){
    for(int j = 0; j <= 1; j++){
        X[i] = j;
        if(i == n){
            ll s1 = 0, s2 = 0;
            for(int idx = 1; idx <= n; idx++){
                if(X[idx] == 1){
                    s1 += 1ll * a[idx];
                }
                else{
                    s2 += 1ll * a[idx];
                }
            }
            res = min(res, abs(s1 - s2));
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){
    TranHungss();
    cin >> n;
	for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    Try(1);
    cout << res << endl;
}