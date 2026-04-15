#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    multiset<int> st;
    for(auto &it : a){
        cin >> it;
        st.insert(it);
    }
    for(auto &it : b){
        cin >> it;
    }
    for(int i = 0; i < m; i++){
        auto it = st.upper_bound(b[i]);
        if(it == st.begin()){
            cout << "-1" << endl;
        }
        else{
            --it;
            cout << *it << endl;
            st.erase(it);
        }
    }
}