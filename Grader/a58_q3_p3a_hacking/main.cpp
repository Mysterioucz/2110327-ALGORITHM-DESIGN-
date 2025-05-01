#include <bits/stdc++.h>
using namespace std;

int n,m,k;

vector<vector<int>> g;
vector<int> dist;
vector<int> host;
vector<int> p;

void dijkstra(){
    set<pair<int,int>> s;
    for(int e:host){
        dist[e] = p[e];
        s.insert({p[e],e});
    }
    while(!s.empty()){
        int u = s.begin()->second, cost = s.begin()->first;
        s.erase(s.begin());
        for(int nb:g[u]){
            if(dist[nb] > cost + p[nb]){
                if(s.find({dist[nb],nb}) != s.end()) s.erase(s.find({dist[nb],nb}));
                dist[nb] = cost + p[nb];
                s.insert({dist[nb],nb});
            }
        }
    }
}

int main(){ 
    cin >> n >> m >> k;
    dist.resize(n,INT_MAX/2);
    g.resize(n);
    host.resize(k);
    p.resize(n);
    for(int i = 0;i < k;i++) cin >> host[i];
    for(int i = 0;i < n;i++) cin >> p[i];
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dijkstra();
    cout << *max_element(dist.begin(),dist.end()) << "\n";
    return 0;   
}