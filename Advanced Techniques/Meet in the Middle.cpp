#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> Subset_Sum(vector<int> a){
    vector<int> res;
    for(int mask = 0; mask < (1 << a.size()); mask++){
        int sum = 0;
        for(int i = 0; i < a.size(); i++){
            if(mask & (1 << i)){
                sum += a[i];
            }
        }
        res.push_back(sum);
    }
    sort(begin(res), end(res));
    return res;
}

signed main(){
    TranHungss();
    int n, s;
    cin >> n >>  s;
    int arr[n];
    for(int &x : arr) cin >> x;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        if(i < n / 2){
            a.push_back(arr[i]);
        }
        else{
            b.push_back(arr[i]);
        }
    }
    a = Subset_Sum(a);
    b = Subset_Sum(b);
    int ans = 0;
    for(int i = 0; i < a.size(); i++){
        auto it1 = lower_bound(begin(b), end(b), s - a[i]);
        auto it2 = upper_bound(begin(b), end(b), s - a[i]);
        ans += it2 - it1;
    }
    cout << ans << endl;
}