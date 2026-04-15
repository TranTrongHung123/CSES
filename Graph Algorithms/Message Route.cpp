#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, m;
int visited[100005], parent[100005];
vector<int> Ke[100005];

void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        Ke[x].push_back(y);
        Ke[y].push_back(x);
    }
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto x : Ke[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = 1;
                parent[x] = v;
            }
        }
    }
}

void Path(){
    BFS(1);
    if(!visited[n]){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> res;
        while(n != 1){
            res.push_back(n);
            n = parent[n];
        }
        res.push_back(1);
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        for(auto x : res){
            cout << x << " ";
        }
    }
}

int main(){
    TranHungss();
    input();
    Path();
}