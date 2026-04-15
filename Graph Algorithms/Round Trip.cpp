#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, m, start, target;
vector<int> Ke[100005];
int visited[100005], parent[100005];

void input(){
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        Ke[x].push_back(y);
        Ke[y].push_back(x);
    }
}

bool DFS(int u){
    visited[u] = 1;
    for(int v : Ke[u]){
        if(!visited[v]){
            parent[v] = u;
            if(DFS(v)){
                return true;
            }
        }
        else if(v != parent[u]){
            start = v;
            target = u;
            return true;
        }
    }
    return false;
}

int main(){
    TranHungss();
    input();
    for(int u = 1; u <= n; u++){
        if(!visited[u]){
            if(DFS(u)){
                vector<int> res;
                res.push_back(start);
                while(target != start){
                    res.push_back(target);
                    target = parent[target];
                }
                res.push_back(start);
                cout << res.size() << endl;
                reverse(begin(res), end(res));
                for(auto it : res){
                    cout << it << " ";
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}