#include <bits/stdc++.h>
using namespace std;

bool dfs_cycle(int a,const vector<vector<int>> &g,vector<bool> &visited,int parent){
    visited[a] = true;
    for(int v:g[a]){
        if(!visited[v]){
            if(dfs_cycle(v,g,visited,a)) return true;
        }
        else if(v != parent) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,e;
        cin >> n >> e;
        vector<vector<int>> g(n);// collect graph using adjacency list
        while(e--){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> visited(n); // vertice numbered from 0 to n-1
        bool cycle = 0;
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                cycle = dfs_cycle(i,g,visited,-1);
                if(cycle){
                    cout << "YES" << "\n";
                    break;
                }
            }
        }
        if(!cycle) cout << "NO" << "\n";

    }
    return 0;
}