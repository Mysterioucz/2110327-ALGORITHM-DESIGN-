#include <bits/stdc++.h>
using namespace std;

void get(int idx, const vector<int> &v, const unordered_map<int,int> &c){
    idx--; // The problem assume that index start at 1 not 0
    int i = 0;
    for(auto &e:v){
        if(i <= idx && idx < i + c.at(e)){
            cout << e << "\n";
            return;
        }
        i += c.at(e);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    // freopen("output.txt","w",stdout); // for output check
    int n,q,tmp,e;
    cin >> n >> q;

    vector<int> data;vector<int> pos;
    unordered_map<int,int> c;
    for(int i = 0;i < n;i++){
        cin >> e >> tmp;
        if(c.find(e) == c.end()) data.push_back(e);
        c[e] += tmp;
    }
    sort(data.begin(),data.end());
    pos.resize(data.size());
    pos[0] = c[data[0]] - 1;
    for(int i = 1;i < data.size();i++){
        pos[i] = pos[i-1] + c[data[i]];
    }

    while(q--){
        cin >> tmp;
        // get(tmp,data,c);
        cout << data[lower_bound(pos.begin(),pos.end(),tmp - 1) - pos.begin()] << "\n";
    }
    return 0;
}