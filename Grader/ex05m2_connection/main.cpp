#include <bits/stdc++.h>
using namespace std;

int n,e,k;

int bfs(int a, const vector<vector<int>> &g){
    vector<int> dist(n,-1);
    int total = 0;
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    while(q.size() > 0){
        int u = q.front();
        if(dist[u] > k) break;
        q.pop();
        for(int v:g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
                total += dist[u] < k;
            }
        }
    }
    return total + 1;
}

int main(){
    cin >> n >> e >> k;
    vector<vector<int>> g(n);
    while(e--){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    pair<int,int> res = {0,0}; // {vertex,number of friend}
    for(int i = 0;i < n;i++){
        vector<bool> visited(n);
        int deg_k_friend = bfs(i,g);
        // printf("\nVertex %d : %d\n",i,deg_k_friend);
        if(res.second < deg_k_friend){
            res = {make_pair(i,deg_k_friend)};
        }
    }
    cout << res.second;
    return 0;
}