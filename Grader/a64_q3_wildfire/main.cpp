#include <bits/stdc++.h>
using namespace std;

int n,m,k,total = 0;
vector<int> v; // store value of each node
vector<vector<int>> g; // collect directed graph using adjacency list
vector<int> wf; // store wild fire

void bfs(int a,vector<bool> &visited){
    queue<int> q;
    q.push(a);
    visited[a] = true;
    while(q.size() > 0){
        int u = q.front();
        total -= v[u];
        q.pop();
        for(int b:g[u]){
            if(!visited[b]){
                q.push(b);
                visited[b] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m >> k;
    g.resize(n);v.resize(n);wf.resize(k);
    for(int i = 0;i < n;i++){ 
        cin >> v[i];
        total += v[i];
    }
    for(int &e:wf) cin >> e;
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<bool> visited(n);
    vector<int> res;
    for(int f:wf){ // each field in wildfire
        if(!visited[f]) bfs(f,visited);
        res.push_back(total);
    }
    for(int r:res) cout << r << " ";
    return 0;
}