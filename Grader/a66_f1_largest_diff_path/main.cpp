#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> c;
vector<int> inDeg;
vector<int> minVal;

int n,m, res = 0;

vector<int> topo_sort(){
    vector<int> ans;
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }
    while(q.size() > 0){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int b:g[u]){
            minVal[b] = min(minVal[b],minVal[u]);
            inDeg[b]--;
            if(inDeg[b] == 0) q.push(b);
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    g.resize(n);
    c.resize(n);
    inDeg.resize(n);
    for(int i = 0;i < n;i++) cin >> c[i];
    minVal = c;
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        inDeg[b]++;
    }
    
    vector<int> topo_g = topo_sort();
    for(int v:topo_g){
        res = max(c[v] - minVal[v],res); 
    }
    cout << res;

    return 0;
}