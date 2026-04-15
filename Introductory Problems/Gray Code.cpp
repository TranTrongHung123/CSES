#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, X[100];

string binary_to_gray(string s){
    string res = s.substr(0, 1);
    for(int i = 1; i < s.size(); i++){
        if(s[i-1] == s[i]){
            res += "0";
        }
        else{
            res += "1";
        }
    }
    return res;
}

void Try(int i){
    for(int j = 0; j <= 1; j++){
        X[i] = j;
        if(i == n){
            string tmp = "";
            for(int l = 1; l <= n; l++){
                tmp += to_string(X[l]);
            }
            cout << binary_to_gray(tmp) << endl;
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){
    TranHungss();
    cin >> n;
    Try(1);
}