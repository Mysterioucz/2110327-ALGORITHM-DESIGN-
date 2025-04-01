#include <bits/stdc++.h>
using namespace std;

int n,m,q;
vector<vector<int>> g;
vector<int> res;
vector<int> p;
vector<int> s;

int findSet(int x){
    if(p[x] == -1) return x;
    p[x] = findSet(p[x]);
    return p[x];
}

void unionSet(int x,int y){
    int s1 = findSet(x);
    int s2 = findSet(y);
    if(s[s1] > s[s2]){
        p[s2] = s1;
        s[s1] += s[s2];
    }else{
        p[s1] = s2;
        s[s2] += s[s1];
    }
}

int kruskral(){
    int dsSize = n;
    for(auto t:g){
        int u = t[1],v = t[2];
        if(findSet(u) != findSet(v)){
            unionSet(u,v);
            dsSize--;
            res[dsSize] = t[0];
        }
    }
    return dsSize;
}

int main(){
    cin >> n >> m >> q;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        g.push_back({c,a,b});
    }
    vector<int> shop(q);
    for(int i = 0;i < q;i++){
        cin >> shop[i];
    }
    sort(g.begin(),g.end());
    p.resize(n,-1);
    s.resize(n,1);
    res.resize(n+1);
    kruskral();
    for(int d:shop){
        cout << res[d] << "\n";
    }

    return 0;
}