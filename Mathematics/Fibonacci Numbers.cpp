#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int mod = 1000000007;

struct Matrix {
    ll x[100][100];
    Matrix(){
        memset(x, 0, sizeof(x));
    }
};

Matrix Tich(Matrix h, Matrix k) {
    Matrix res;
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= 2; j++){
            ll tmp = 0;
            for(int l = 1; l <= 2; l++){
                tmp += (h.x[i][l] * k.x[l][j]);
                tmp %= mod;
            }
            res.x[i][j] = tmp;
        }
    }
    return res;
}

Matrix Luy_Thua(Matrix a, ll n) {
    Matrix res;
    for(int i = 1; i <= 2; i++){
        for(int j = 1; j <= 2; j++){
            if(i == j){
                res.x[i][j] = 1;
            }
            else{
                res.x[i][j] = 0;
            }
        }
    }
    while(n){
        if(n % 2 == 1){
            res = Tich(res, a);
        }
        n /= 2;
        a = Tich(a, a);
    }
    return res;
}

int main(void){
    TranHungss();
    ll n;
    cin >> n;
    Matrix a;
    a.x[1][1] = a.x[1][2] = a.x[2][1] = 1;
    a.x[2][2] = 0;
    Matrix ans = Luy_Thua(a, n);
    cout << ans.x[1][2] << endl;
}