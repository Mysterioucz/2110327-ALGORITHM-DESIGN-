#include <bits/stdc++.h>
using namespace std;

int n,m,k,v;
vector<vector<pair<int,int>>> g; // collect as adjacency list each have pair that {node,weight}

vector<int> bellman_ford(){
    vector<int> dist(n,INT_MAX/2);
    dist[v] = 0;
    for(int i = 0;i < n-1;i++){
        for(int j = 0;j < n;j++){
            for(auto p:g[j]){
                if(dist[p.first] > dist[j] + p.second){
                    dist[p.first] = dist[j] + p.second;
                }
            }
        }
    }
    return dist;
}

int main(){
    cin >> n >> m >> k >> v;
    vector<int> ques(k);
    for(int &e:ques) cin >> e;
    g.resize(n);
    while(m--){
        int a,b,w;
        cin >> a >> b >> w;
        g[b].push_back({a,w});
    }
    vector<int> tmp = bellman_ford();
    int res = INT_MAX;
    for(int e:ques) res = min(tmp[e],res);
    cout << res;
    return 0;
}