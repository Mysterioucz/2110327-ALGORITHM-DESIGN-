#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin >> n;

    vector<pair<int,int>> v,res;
    while(n--){
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    res.push_back(v[0]);
    for(auto e:v){
        a = res[res.size() - 1].first;
        b = res[res.size() - 1].second;
        if(e.first - b >= 0){
            if(e.first - b == 1 || e.first - b == 0){
                res[res.size() - 1] = {a,e.second};
            }else{
                res.push_back(e);
            }
        }else{
            res[res.size() - 1] = {a,max(b,e.second)};
        }
    }
    for(auto e:res){
        cout << e.first << " " << e.second << " ";
    }

    return 0;
}