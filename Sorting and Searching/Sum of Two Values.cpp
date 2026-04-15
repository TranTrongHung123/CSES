#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    int n, s;
    cin >> n >> s;
    pair<int,int> a[n + 1];
    int b[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i].first;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    bool check = false;
    for(int i = 1; i < n; i++){
        auto it = lower_bound(b + i + 1, b + n + 1, s - b[i]);
        if(it != (b + n + 1)){
            if((*it) == (s - b[i])){
                if(a[i].second > a[(it - b)].second){
                    swap(a[i].second, a[(it - b)].second);
                }
                cout << a[i].second << " " << a[(it - b)].second << endl;
                check = true;
                break;
            }
        }
    }
    if(!check){
        cout << "IMPOSSIBLE" << endl;
    }
}