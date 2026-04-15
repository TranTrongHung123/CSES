#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<pair<int,int>> res;

void Town_of_HaNoi(int n, char start, char end, char extra){
    if(n == 0){
        return;
    }
    Town_of_HaNoi(n - 1, start, extra, end);
    res.push_back({start - '0', end - '0'});
    Town_of_HaNoi(n - 1, extra, end, start);
}

int main(){
    TranHungss();
    int n;
    cin >> n;
    Town_of_HaNoi(n, '1', '3', '2');
    cout << res.size() << endl;
    for(auto x : res){
        cout << x.first << " " << x.second << endl;
    }
}