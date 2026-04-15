#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int solve(int n){
    int res = 0;
    for(int i = 5; i <= n; i *= 5){
        res += (n / i);
    }
    return res;
}

int main(){
    TranHungss();
    int n;
    cin >> n;
    cout << solve(n) << endl;
}