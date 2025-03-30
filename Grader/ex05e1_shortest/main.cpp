#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> m;
vector<pair<int,int>> mv = {{0,-1},{0,1},{-1,0},{1,0}};
int r,c;

int bfs(int a,int b){
    vector<vector<int>> dist(r,vector<int>(c,-1));
    queue<vector<int>> q;
    q.push({a,b});
    dist[a][b] = 0;
    while(q.size() > 0){
        vector<int> u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int new_r = u[0] + mv[i].first;
            int new_c = u[1] + mv[i].second;
            if((new_r >= 0 && new_c >= 0 && new_r < r && new_c < c) && (dist[new_r][new_c] == -1) && (m[new_r][new_c])){
                q.push({new_r,new_c});
                dist[new_r][new_c] = dist[u[0]][u[1]] + 1;
            }
        }
    }
    return dist[r-1][c-1];
}
int main(){
    cin >> r >> c;
    m.resize(r,vector<bool>(c));
    for(int i = 0;i < r;i++){
        string tmp;
        cin >> tmp;
        for(int j = 0;j < c;j++){
            m[i][j] = (tmp[j] == '.');
        }
    }
    cout << bfs(0,0);
    return 0;
}