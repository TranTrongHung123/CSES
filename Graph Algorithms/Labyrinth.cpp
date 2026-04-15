#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, m;
char a[1005][1005];
pair<int,int> start, target;

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'A'){
                start = {i, j};
            }
            if(a[i][j] == 'B'){
                target = {i, j};
            }
        }
    }
}

struct Data{
    pair<int,int> pir;
    char c;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
Data parent[1005][1005];
string str = "URDL";

void BFS(int i, int j){
    queue<pair<int,int>> q;
    q.push({i, j});
    a[i][j] = '#';
    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();
        for(int k = 0; k < 4; k++){
            int i1 = tmp.first + dx[k];
            int j1 = tmp.second + dy[k];
            if((i1 >= 1) and (i1 <= n) and (j1 >= 1) and (j1 <= m) and (a[i1][j1] != '#')){
                a[i1][j1] = '#';
                q.push({i1, j1});
                parent[i1][j1].pir = {tmp.first, tmp.second};
                parent[i1][j1].c = str[k];
            }
        }
    }
}

void solve(){
    BFS(start.first, start.second);
    if(a[target.first][target.second] != '#'){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        vector<char> vt;
        while(target != start){
            vt.push_back(parent[target.first][target.second].c);
            target = parent[target.first][target.second].pir;
        }
        cout << vt.size() << endl;
        for(int i = vt.size() - 1; i >= 0; i--){
            cout << vt[i];
        }
    }
}

int main(){
    TranHungss();
    input();
    solve();
}