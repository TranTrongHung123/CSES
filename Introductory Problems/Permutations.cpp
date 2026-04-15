#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

void solve(int n){
    if(n == 2 or n == 3){
        cout << "NO SOLUTION" << endl;
        return;
    }
    for(int i = 2; i <= n; i += 2){
        cout << i << " ";
    } 
    for(int i = 1; i <= n; i += 2){
        cout << i << " ";
    }  
}

int main(){
    TranHungss();
    int n;
    cin >> n;
    solve(n);
}