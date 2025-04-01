#include <bits/stdc++.h>
using namespace std;

int n,e;
vector<vector<int>> g;

bool topo_check(vector<int> seq){
    vector<bool> visited(n);
    for(int node:seq){
        visited[node] = true;
        for(int pre:g[node]){
            if(!visited[pre]) return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> e;
    n++;
    g.resize(n);
    while(e--){
        int a,b;
        cin >> a >> b;
        g[b].push_back(a); // for checking prereq
    }
    for(int i = 0;i < 5;i++){
        vector<int> seq;
        for(int j = 1;j < n;j++){
            int tmp;
            cin >> tmp;
            seq.push_back(tmp);
        }
        if(topo_check(seq)) cout << "SUCCESS\n";
        else cout  << "FAIL\n";
    }


    return 0;
}