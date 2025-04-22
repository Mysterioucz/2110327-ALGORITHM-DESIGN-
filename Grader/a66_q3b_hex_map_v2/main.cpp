#include <bits/stdc++.h>
using namespace std;

int r,c,a1,b1,a2,b2;
vector<vector<int>> cost;
vector<vector<pair<int,int>>> dir = {{{0,-1},{0,1},{-1,-1},{-1,0},{1,-1},{1,0}},{{0,-1},{0,1},{-1,0},{-1,1},{1,0},{1,1}}};

int dijkstra(){
    set<vector<int>> s;
    vector<vector<int>> dist(r,vector<int>(c,INT_MAX/2));
    dist[a1-1][b1-1] = 0;
    s.insert({cost[a1-1][b1-1],a1-1,b1-1});
    while(!s.empty()){
        vector<int> curPos = *s.begin();
        int total = curPos[0];
        s.erase(s.begin());
        for(auto d:dir[curPos[1]%2==0]){
            int candR = curPos[1] + d.first,candC = curPos[2] + d.second;
            if(!((0 <= candR && candR < r) && (0 <= candC && candC < c))) continue;
            if(dist[candR][candC] > total + cost[candR][candC]){
                if(s.find({dist[candR][candC],candR,candC}) != s.end()) s.erase({dist[candR][candC],candR,candC});
                dist[candR][candC] = total + cost[candR][candC];
                s.insert({dist[candR][candC],candR,candC});
            }
        }
    }
    return dist[a2-1][b2-1];
}

int main(){
    cin >> r >> c;
    cin >> a1 >> b1 >> a2 >> b2;
    cost.resize(r,vector<int>(c));
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            int tmp;
            cin >> tmp;
            cost[i][j] = tmp;
        }
    }
    cout << dijkstra() << "\n";
    return 0;
}