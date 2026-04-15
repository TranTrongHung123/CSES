#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    int n;
    cin >> n;
    int a[n];
    set<int> st;
    for(auto &it : a){
        cin >> it;
        st.insert(it);
    }
    cout << st.size() << endl;
}