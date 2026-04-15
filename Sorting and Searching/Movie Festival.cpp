#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool cmp(pair<int,int> x, pair<int,int> y){
    return x.second < y.second;
}

int main(){
    TranHungss();
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(auto &x : a){
        cin >> x.first >> x.second;
    }
    sort(a, a + n, cmp);
    int cnt = 1, pos = a[0].second;
    for(int i = 1; i < n; i++){
        if(a[i].first >= pos){
            ++cnt;
            pos = a[i].second;
        }
    }
    cout << cnt << endl;
}