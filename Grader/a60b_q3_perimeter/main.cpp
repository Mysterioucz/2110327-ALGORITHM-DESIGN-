#include <bits/stdc++.h>
using namespace std;

int n,e,k,res = 0;
vector<vector<int>> g;
vector<int> dist;

void bfs(int a){
    dist[a] = 0;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:g[u]){
            int newDist = dist[u] + 1;
            if(dist[v] == -1 && newDist <= k){
                if(newDist == k) res++;
                dist[v] = newDist;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n >> e >> k;
    n++; // there n + 1 location (1 for base n for outpost)
    g.resize(n + 1);
    dist.resize(n + 1,-1);
    while(e--){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a); // undirected graph bidirectionial edge
    }
    bfs(0);
    cout << res;
    return 0;
}