#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;// Collect graph using Adjacency List

void dfs(int a,vector<int> &visited,int grNum){
    visited[a] = grNum;
    for(int v:g[a]){
        if(!visited[v]){
            dfs(v,visited,grNum);
        }
    }
}

int main(){
    int v,e;
    cin >> v >> e;
    g.resize(v + 1);
    for(int i = 0;i < e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> visited(v,0);
    int grNum = 1;
    for(int i = 1;i < v + 1;i++){
        if(!visited[i]){
            dfs(i,visited,grNum);
            grNum += 1;
        }   
    }

    cout << grNum - 1;
    return 0;
}