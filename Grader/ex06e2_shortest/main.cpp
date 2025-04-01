#include <bits/stdc++.h>
using namespace std;

int n,e,s;
vector<vector<pair<int,int>>> g; // collect graph using adjacency list with pair that mean {node,cost}

vector<int> bellman_ford(int a){
    vector<int> dist(n,INT_MAX/2);
    dist[a] = 0;
    for(int i = 0;i < n-1;i++){
        for(int j = 0;j < n;j++){
            for(auto p:g[j]){
                if(dist[p.first] > dist[j] + p.second){
                    dist[p.first] = dist[j] + p.second;
                }
            }
        }
    }
    for(int j = 0;j < n;j++){ // Negative Cycle Detection
        for(auto p:g[j]){
            if(dist[p.first] > dist[j] + p.second){
                return {-1};
            }
        }
    }
    return dist;
}

int main(){
    cin >> n >> e >> s;
    g.resize(n);
    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
    }
    vector<int> res = bellman_ford(s);
    for(auto e:res) cout << e << " ";
    return 0;
}