#include <bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<int>> m;
vector<vector<int>> cost;
vector<pair<int,int>> mov = {{1,0},{-1,0},{0,1},{0,-1}};

void dijkstra(pair<int,int> a){
    vector<vector<bool>> taken(r,vector<bool>(c));
    set<pair<int,pair<int,int>>> s;
    cost[a.first][a.second] = 0;
    s.insert({0,a});
    while(!s.empty()){
        pair<int,pair<int,int>> tmp = *s.begin();
        pair<int,int> u = tmp.second;
        s.erase(tmp);
        for(auto p:mov){
            int nr = u.first + p.first,nc = u.second + p.second;
            if(!((nr >= 0 && nr < r)&&(nc >= 0 && nc < c))) continue;
            int newCost = tmp.first + m[nr][nc];
            if((cost[nr][nc] > newCost)){
                if(s.find({cost[nr][nc],{nr,nc}}) != s.end()) s.erase({cost[nr][nc],{nr,nc}});
                cost[nr][nc] = newCost;
                s.insert({newCost,{nr,nc}});
            }
        }
    }

}

int main(){
    cin >> r >> c;
    m.resize(r,vector<int>(c));
    cost.resize(r,vector<int>(c,INT_MAX));
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin >> m[i][j];
        }
    }
    dijkstra({0,0});
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
}