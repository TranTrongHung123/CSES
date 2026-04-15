#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TranHungss();
    string s;
    cin >> s;
    int len = s.size();
    map<char,int> mp;
    for(auto x : s){
        ++mp[x];
    }
    int cnt = 0;
    for(auto x : mp){
        if(x.second % 2 != 0){
            ++cnt;
        }
    }
    if(len % 2 == 0){
        if(cnt != 0){
            cout << "NO SOLUTION" << endl;
        }
        else{
            string str = "";
            for(auto x : mp){
                for(int i = 1; i <= (x.second/2); i++){
                    str += x.first;
                }
            }
            string tmp = str;
            reverse(tmp.begin(), tmp.end());
            cout << str + tmp << endl;
        }
    }
    else{
        if(cnt != 1){
            cout << "NO SOLUTION" << endl;
        }
        else{
            char c;
            string str = "";
            for(auto x : mp){
                if(x.second % 2 != 0){
                    c = x.first;
                }
                for(int i = 1; i <= (x.second/2); i++){
                    str += x.first;
                }
            }
            string tmp = str;
            reverse(tmp.begin(), tmp.end());
            cout << str + c + tmp << endl;           
        }
    }
}