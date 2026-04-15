#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll Number_Spiral(ll Y, ll X){
    if (Y > X) {
        ll ans = (Y - 1) * (Y - 1);
        if (Y % 2 != 0) {
            ans += X;
        }
        else {
            ans += (2 * Y - X);
        }
        return ans;
    }
    else{
        ll ans = (X - 1) * (X - 1);
        if (X % 2 == 0) {
            ans += Y;
        }
        else {
            ans += (2 * X - Y);
        }
        return ans;
    }
}

int main(){
    TranHungss();
    int TC;
    cin >> TC;
    while(TC--){
        ll Y, X;
        cin >> Y >> X;
        cout << Number_Spiral(Y, X) << endl;
    }
}