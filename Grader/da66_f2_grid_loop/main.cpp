#include <bits/stdc++.h>
using namespace std;

int r,c;
vector<vector<pair<int,int>>> mov;
vector<vector<int>> g;
vector<int> low,ids;
vector<bool> onStack;
pair<int,int> res = {0,0}; // {count of SCC, longest scc }
stack<int> s;
int id = 0;

void dfs(int a){
    s.push(a);
    onStack[a] = true;
    ids[a] = low[a] = id++;

    for (int b : g[a]) {
        if (ids[b] == -1) {
            dfs(b);
            low[a] = min(low[a], low[b]); // Update low[a] after DFS returns
        } else if (onStack[b]) {
            low[a] = min(low[a], ids[b]); // Use ids[b] instead of low[b]
        }
    }

    if(ids[a] == low[a]){
        int count = 0;
        string debug = "";
        while(s.size() > 0){
            int u = s.top();
            s.pop();
            onStack[u] = false;
            low[u] = ids[a];
            count++;
            debug += to_string(u) + " ";
            if(u == a) break;
        }
        if(count > 3) { // cycle in grid must be more than 4 vertex
            res.first++;
            res.second = max(res.second,count);
        }
    }
}

int vertex_convert(int a,int b){ // r,c
    if(!((a >= 0 && a < r) && (b >= 0 && b < c))) return -1;
    return (a*c) + (b);
}

void init(){
    g.resize(r*c);
    low.resize(r*c);
    ids.resize(r*c,-1);
    onStack.resize(r*c);
    mov.resize(7);
    mov[1] = {{0,-1},{0,1}};
    mov[2] = {{-1,0},{1,0}};
    mov[3] = {{-1,0},{0,1}};
    mov[4] = {{0,1},{1,0}};
    mov[5] = {{1,0},{0,-1}};
    mov[6] = {{0,-1},{-1,0}};
}

int main(){
    cin >> r >> c;
    init();
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            int tmp_mov,cur_node = vertex_convert(i,j);
            cin >> tmp_mov;
            for(auto p:mov[tmp_mov]){
                int nbr = vertex_convert(i + p.first,j+p.second);
                if(nbr != -1) g[cur_node].push_back(nbr);
            }
        }
    }
    for(int i = 0;i < r*c;i++){
        if(ids[i] == -1) dfs(i);
    }
    cout << res.first << " " << res.second;
    return 0;
}