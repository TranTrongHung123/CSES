#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    int n, x;
    cin >> n >> x;
    int a[n];
    for(auto &it : a){
        cin >> it;
    }
    sort(a, a + n);
    int left = 0, right = n-1, cnt = 0;
    while(left <= right){
        ++cnt;
        if((a[left] + a[right]) <= x){
            ++left;
            --right;
        }
        else{
            --right;
        }
    }
    cout << cnt << endl;
}