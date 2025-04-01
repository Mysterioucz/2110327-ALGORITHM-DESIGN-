#include <bits/stdc++.h>
using namespace std;

int r,c,k;
vector<vector<int>> m;
vector<vector<int>> dist;
vector<pair<int,int>> mov = {{0,1},{0,-1},{-1,0},{1,0}};

void bfs(int a,int b){
    queue<pair<int,int>> q;
    q.push({a,b});
    dist[a][b] = 0;
    while(q.size() > 0){
        pair<int,int> u = q.front();
        q.pop();
        int new_dist = dist[u.first][u.second] + 1;
        for(pair<int,int> p:mov){
            int nr = u.first + p.first ,nc = u.second + p.second;
            if(!((nr >= 0 && nr < r)&&(nc >= 0 && nc < c))) continue;
            if(new_dist <= k && m[nr][nc] != 1 && (dist[nr][nc] == -1 || dist[nr][nc] > new_dist)){
                m[nr][nc] = 2;
                q.push({nr,nc});
                dist[nr][nc] = new_dist;
            }
        }
    }
}

int main(){
    cin >> r >> c >> k;
    m.resize(r,vector<int>(c));
    vector<pair<int,int>> ground;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin >> m[i][j];
            if(m[i][j] == 1) ground.push_back({i,j});
        }
    }
    
    dist.resize(r,vector<int>(c,-1));
    for(auto p:ground) bfs(p.first,p.second);

    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }



    return 0;
}