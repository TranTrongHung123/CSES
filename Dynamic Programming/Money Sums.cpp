#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, a[101], dp[100001] = {1};

int main(){
    TranHungss();
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int s = 100000; s >= 1; s--){
            if(s - a[i] >= 0 && dp[s - a[i]] == 1){
                dp[s] = 1;
            }
        }
    }
    set<int> st;
    for(int i = 1; i <= 100000; i++){
        if(dp[i] == 1){
            st.insert(i);
        }
    }
    cout << st.size() << endl;
    for(auto x : st){
        cout << x << " ";
    }
}