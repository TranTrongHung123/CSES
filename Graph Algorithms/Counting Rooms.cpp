#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, m;
char a[1005][1005];

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            a[i][j] = s[j];
        }
    }
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void Try(int i, int j){
    a[i][j] = '#';
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if((i1 >= 1) and (i1 <= n) and (j1 >= 1) and (j1 <= m) and (a[i1][j1] == '.')){
            Try(i1, j1);
        }
    }
}

int main(){
    TranHungss();
    input();
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '.'){
                ++cnt;
                Try(i, j);
            }
        }
    }
    cout << cnt << endl;
}