#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define TranHungss(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

char a[100][100];
int mark[100][100], cot[100], cheo1[100], cheo2[100];
int cnt = 0;

void Try(int i){
    for(int j = 1; j <= 8; j++){
        if(!cot[j] and !cheo1[i+j-1] and !cheo2[i-j+8] and !mark[i][j]){
            cot[j] = 1; cheo1[i+j-1] = 1; cheo2[i-j+8] = 1; mark[i][j] = 1;
            if(i == 8){
                ++cnt;
            }
            else{
                Try(i + 1);
            }
            cot[j] = 0; cheo1[i+j-1] = 0; cheo2[i-j+8] = 0; mark[i][j] = 0;
        }
    }
}

int main(){
    TranHungss();
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cin >> a[i][j];
            if(a[i][j] == '*'){
                mark[i][j] = 1;
            }
        }
    }
    Try(1);
    cout << cnt << endl;
}