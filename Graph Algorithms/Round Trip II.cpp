#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, m, start, target;
vector<int> Ke[100001];
int color[100005], parent[100005];

void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        Ke[x].push_back(y);
    }
}

bool DFS(int u){
    color[u] = 1;
    for(int v : Ke[u]){
        if(color[v] == 0){
            parent[v] = u;
            if(DFS(v)){
                return true;
            }
        }
        else if(color[v] == 1){
            start = v;
            target = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

int main(){
    TranHungss();
    input();
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            if(DFS(i)){
                vector<int> cycle;
                cycle.push_back(start);
                while(target != start){
                    cycle.push_back(target);
                    target = parent[target];
                }
                cycle.push_back(start);
                reverse(begin(cycle), end(cycle));
                cout << cycle.size() << endl;
                for(auto it : cycle){
                    cout << it << " ";
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}