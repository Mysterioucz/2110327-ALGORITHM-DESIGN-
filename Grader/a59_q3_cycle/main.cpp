#include <bits/stdc++.h>
using namespace std;

int res = -1;
int n;
vector<vector<int>> g;

void dfs(int a){
    vector<pair<int,int>> dist(n,{-1,-1}); // {dist,par}
    dist[a].first = 0;
    stack<int> s;
    s.push(a);
    while(s.size() > 0){
        int u = s.top();
        // printf("%d ",u);
        s.pop();
        for(int b:g[u]){
            if(dist[b].first == -1){
                s.push(b);
                dist[b] = {dist[u].first + 1,u};
            }else if(b != dist[u].second && res == -1){
                int par = dist[b].second;
                res = (dist[u].first + dist[b].first + 1) - 2*dist[par].first;
            }
        }
    }

}

int main(){
    cin >> n;
    g.resize(n);
    for(int i= 0;i < n;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(n-1);
    cout << "\n";
    cout << res;
    return 0;
}