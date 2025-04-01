#include <bits/stdc++.h>
using namespace std;
// directed graph
// no negative edge we acan use dijkstra

int n;
vector<vector<int>>g;

vector<int> dijkstra(int a){
    vector<int> dist(n,INT_MAX/2);
    dist[a] = 0;
    set<pair<int,int>> s;
    s.insert({0,a});
    while(!s.empty()){
        pair<int,int> u = *s.begin();
        s.erase(u);
        for(int i = 0;i < n;i++){
            if(g[u.second][i] == -1 || i == u.second) continue;
            if(dist[i] > u.first + g[u.second][i]){
                if(s.find({dist[i],i}) != s.end()) s.erase({dist[i],i});
                dist[i] = u.first + g[u.second][i];
                s.insert({dist[i],i});
            }
        }
    }
    return dist;
}


int main(){
    cin >> n;
    int res = -1;
    g.resize(n,vector<int>(n));
    for(auto &r:g){
        for(auto &c:r) cin >> c;
    }
    vector<int> dist = dijkstra(0);
    // cout << "Test dist\n";
    for(auto d:dist){
        // cout << d << " ";
        if(d == INT_MAX/2){
            res = -1;
            break;
        }
        res = max(res,d);
    }
    cout << res;
    return 0;
}