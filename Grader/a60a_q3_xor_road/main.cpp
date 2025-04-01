#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull n;
ull res = 0;
vector<ull> g;


void prim(int a){
    vector<bool> taken(n);
    vector<ull> cost(n,0);
    set<pair<ull,ull>> s;
    s.insert({0,a});
    cost[a] = 0;
    while(!s.empty()){
        pair<ull,ull> u = *s.rbegin();
        s.erase(u);
        taken[u.second] = true;
        res += u.first;
        for(int i = 0;i < n;i++){
            // if(i == u.second) continue;
            if(cost[i] < (g[u.second] ^ g[i]) && taken[i] == false){
                if(s.find({cost[i],i}) != s.end()) s.erase({cost[i],i});
                cost[i] = g[i] ^ g[u.second];
                s.insert({cost[i],i});
            }
        }
    }
}

int main(){
    cin >> n;
    g.resize(n);
    for(int i = 0;i < n;i++) cin >> g[i];
    prim(0);
    cout << res;
    return 0;
}