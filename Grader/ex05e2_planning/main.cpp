#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> inDeg;
int n;

string topo_sort(){
    string ans;
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(inDeg[i] == 0) q.push(i);
    }
    while(q.size() > 0){
        int u = q.front();
        q.pop();
        ans += to_string(u) + " ";
        for(int b:g[u]){
            inDeg[b]--;
            if(inDeg[b] == 0){
                q.push(b);
            }
        }
    }
    return ans;
}

int main(){
    cin >> n;
    g.resize(n);
    inDeg.resize(n);
    for(int i = 0;i < n;i++){
        int num,a;
        cin >> num;
        while(num--){
            cin >> a;
            g[a].push_back(i);
            inDeg[i]++;
        }
    }
    cout << topo_sort();
    return 0;
}