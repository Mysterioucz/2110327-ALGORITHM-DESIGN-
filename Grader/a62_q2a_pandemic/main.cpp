#include <bits/stdc++.h>
using namespace std;

int r,c,t,res = 0; // t in this problem is refer to day but it's actually distance in graph
vector<vector<int>> m;
vector<vector<int>> dist;
vector<pair<int,int>> mov = {{1,0},{-1,0},{0,-1},{0,1}};

void bfs(pair<int,int> a){
    dist[a.first][a.second] = 0;
    queue<pair<int,int>> q;
    q.push(a);
    res++;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        int newDist = dist[u.first][u.second] + 1;
        for(auto p:mov){
            int nr = u.first + p.first,nc = u.second + p.second;
            if(!((nr >= 0 && nr < r)&&(nc >= 0 && nc < c))) continue;
            if(m[nr][nc] == 0 && newDist <= t && (dist[nr][nc] == -1 || newDist < dist[nr][nc] )){
                if(dist[nr][nc] == -1){
                    res++;
                }
                dist[nr][nc] = newDist;
                q.push({nr,nc});

            }
        }
    }
}

int main(){
    cin >> r >> c >> t;
    m.resize(r,vector<int>(c));
    dist.resize(r,vector<int>(c,-1));
    vector<pair<int,int>> host;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin >> m[i][j];
            if(m[i][j] == 1) host.push_back({i,j});
        }
    }
    for(auto p:host){
        bfs(p);
    }
    cout << res;

    return 0;
}