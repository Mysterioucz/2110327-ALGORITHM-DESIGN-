#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> deg;



bool bfs(int a,vector<bool> &visited){
    visited[a] = true;
    queue<int> q;
    q.push(a);
    bool check = true;
    while(q.size() > 0){
        int u = q.front();
        q.pop();
        if(deg[u] > 2) check = false;
        for(int b:g[u]){
            if(!visited[b]){
                q.push(b);
                visited[b] = true;
            }
        }
    }

    return check;
}

int main(){
    int v,e;
    cin >> v >> e;
    g.resize(v);
    deg.resize(v,0);
    for(int i = 0;i < e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;deg[b]++;
    }
    vector<bool> visited(v);
    int c = 0;
    for(int i = 0;i < v;i++){
        if(!visited[i] && deg[i] <= 1){
            c += bfs(i,visited);
        }
    }
    cout << c;
    return 0;
}