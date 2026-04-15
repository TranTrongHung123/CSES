#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    string s;
    cin >> s;
    sort(begin(s), end(s));
    vector<string> res;
    do{
        res.push_back(s);
    }while(next_permutation(begin(s), end(s)));
    cout << res.size() << endl;
    for(auto it : res){
        cout << it << endl;
    }
}