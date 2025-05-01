#include <bits/stdc++.h>

using namespace std;

int r,c,k;
vector<vector<int>> g;
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
vector<pair<int,int>> startPos;
vector<vector<pair<int,int>>> distRes; // {minDist,maxDist}

void bfs(){
    for(pair<int,int> s:startPos){
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX/2));
        dist[s.first][s.second] = 0;
        queue<pair<int,int>> q;
        q.push(s);
        while(!q.empty()){
            pair<int,int> u = q.front();
            q.pop();
            for(auto &d:dir){
                int nr = u.first + d.first,nc = u.second + d.second;
                if(!((0 <= nr && nr < r)&&(0 <= nc && nc < c))) continue;
                if(g[nr][nc] == 1) continue;
                if(dist[nr][nc] > dist[u.first][u.second] + 1){
                    dist[nr][nc] = dist[u.first][u.second] + 1;
                    q.push({nr,nc});
                }
            }
        }
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                int curDist = dist[i][j];
                distRes[i][j].first = min(curDist,distRes[i][j].first);
                distRes[i][j].second = max(curDist,distRes[i][j].second);
            }
        }
    }
}

int main(){
    cin >> r >> c >> k;
    g.resize(r,vector<int>(c));
    distRes.resize(r,vector<pair<int,int>>(c,{INT_MAX/2,INT_MIN/2}));
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin >> g[i][j];
            if(g[i][j] == 2){
                startPos.push_back(make_pair(i,j));
                g[i][j] = 0;
            }
        }
    }
    bfs();
    int res = 0;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            if(distRes[i][j].first > r+c || distRes[i][j].second < 0) continue;
            res += (abs(distRes[i][j].first - distRes[i][j].second) <= k);
        }
    }
    cout << res << "\n";

    return 0;
}