#include <bits/stdc++.h>
using namespace std;
// This problem is shortest path problem (weighted graph all node are = 1)
int n,t1,t2,t3;
vector<vector<int>> g;

vector<int> dijkstra(int a){
    vector<int> dist(n + 1,INT_MAX);
    dist[a] = 0;
    set<pair<int,int>> s;
    s.insert({0,a});
    while(!s.empty()){
        pair<int,int> u = *s.begin();
        s.erase(u);
        for(int v:g[u.second]){
            if(dist[v] > u.first + 1){
                if(s.find({dist[v],v}) != s.end()) s.erase({dist[v],v});
                dist[v] = u.first + 1;
                s.insert({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    cin >> n;
    cin >> t1 >> t2 >> t3;
    g.resize(n+1);
    for(int i = 1;i < n + 1;i++ ){
        int num;
        cin >> num;
        g[i].resize(num);
        for(int &e:g[i]) cin >> e;
    }
    vector<vector<int>> tmp(3);
    tmp[0] = dijkstra(t1);
    tmp[1] = dijkstra(t2);
    tmp[2] = dijkstra(t3);
    int res = INT_MAX;
    for(int i = 1;i < n + 1;i++){
        res = min(res,max(tmp[0][i],max(tmp[1][i],tmp[2][i])));
    }
    cout << res;
    return 0;
}