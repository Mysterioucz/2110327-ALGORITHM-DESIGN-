#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dist;
int n,m;

void floyd_warshall(){
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    dist.resize(n,vector<int>(n,INT_MAX/3));
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for(int i = 0;i < n;i++) dist[i][i] = 0;
    floyd_warshall();
    int res = INT_MIN;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(dist[i][j] == INT_MAX/3) continue;
            res = max(res,dist[i][j]);
        }
    }
    cout << res;
    return 0;
}