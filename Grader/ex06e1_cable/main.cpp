#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> g; // {cost,v}
vector<int> cost,pre;
vector<bool> taken;
int n;
int res = 0;

void prim(){
    set<pair<int,int>> s; // collect {cost,node}
    s.insert({0,0});
    cost[0] = 0;
    while(s.size() > 0){
        int c,u;
        c = s.begin()->first;
        u = s.begin()->second;
        s.erase(s.begin());
        taken[u] = true;
        for(auto v:g[u]){
            if(cost[v.second] > v.first && !taken[v.second]){
                if(s.find(v) != s.end())s.erase(v);
                cost[v.second] = v.first;
                pre[v.second] = u;
                s.insert(v);
            }
        }   
    }
}

int main(){
    cin >> n;
    g.resize(n);
    cost.resize(n,INT_MAX);
    pre.resize(n,-1);
    taken.resize(n,false);
    for(int i = 0;i < n-1;i++){
        for(int k = 1;k <= n-i-1;k++){
            int cost;
            cin >> cost;
            g[i].push_back({cost,i+k});
            g[i + k].push_back({cost,i});
        }
    }
    prim();
    for(int i = 0;i < n;i++) res += cost[i];
    cout << res;
    return 0;
}