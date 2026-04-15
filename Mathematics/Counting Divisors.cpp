#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int f[1000001];

void sieve(){
    for(int i = 1; i <= 1000000; i++){
        f[i] = i;
    }
    for(int i = 2; i <= 1000; i++){
        if(f[i] == i){
            for(int j = i*i; j <= 1000000; j += i){
                if(f[j] == j){
                    f[j] = i;
                }
            }
        }
    }
}

int solve(int n){
    int res = 1;
    while(n != 1){
        int degree = 0;
        int pos = f[n];
        while(n % pos == 0){
            ++degree;
            n /= pos;
        }
        res *= (degree + 1);
    }
    return res;
}

int main(){
    TranHungss();
    sieve();
    int Q;
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}