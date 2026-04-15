#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    string s;
    cin >> s;
    int n = s.size();
    int a[n]; a[0] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            a[i] = a[i-1] + 1;
        }
        else{
            a[i] = 1;
        }
    }
    cout << *max_element(a, a + n) << endl;
}