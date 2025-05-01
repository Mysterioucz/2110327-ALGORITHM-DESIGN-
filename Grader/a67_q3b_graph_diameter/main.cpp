#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<vector<int>> dist;


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
    g.resize(n);
    dist.resize(n,vector<int>(m,INT_MAX/2));
    for(int i = 0;i < n;i++) dist[i][i] = 0;
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a-1].push_back(b-1);
        dist[a-1][b-1] = c;
    }
    floyd_warshall();
    int res = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(dist[i][j] >= INT_MAX/2) continue;
            res = max(res,dist[i][j]);
        }
    }
    cout << res << "\n";
    return 0;
}