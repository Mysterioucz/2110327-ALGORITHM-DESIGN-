#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> low,ids;
vector<bool> onStack;
vector<int> res;
stack<int> s;
int n,id = 0;

void dfs(int a){
    s.push(a);
    onStack[a] = true;
    ids[a] = low[a] = id++;

    for(int b:g[a]){
        if(ids[b] == -1) dfs(b);
        if(onStack[b]) low[a] = min(low[a],low[b]);
    }

    if(ids[a] == low[a]){
        int c = 0;
        while(s.size() > 0){
            int u = s.top();
            s.pop();
            onStack[u] = false;
            low[u] = ids[a];
            c++;
            if(u == a) break;
        }
        res.push_back(c);
    }
}

int main(){
    cin >> n;
    g.resize(n);
    low.resize(n);
    ids.resize(n,-1);
    onStack.resize(n);
    for(int i = 0;i < n;i++){
        int num,a;
        cin >> num;
        while(num--){
            cin >> a;
            g[i].push_back(a);
        }
    }
    for(int i = 0;i < n;i++){
        if(ids[i] == -1) dfs(i);
    }
    sort(res.begin(),res.end());
    for(int e:res) cout << e << " ";

    return 0;
}