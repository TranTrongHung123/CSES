#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void Try(ll n){
    cout << n << " ";
    if(n == 1) return;
    if(n % 2 == 0){
        n /= 2;
        Try(n);
    }
    else{
        n = 3*n + 1;
        Try(n);
    }
}

int main(){
    TranHungss();
    ll n;
    cin >> n;
    Try(n);
}