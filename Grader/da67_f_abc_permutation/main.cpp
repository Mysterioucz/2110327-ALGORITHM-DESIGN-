#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void perm(int n,string sol, map<string,int> &count){
    if(sol.size() < n){
        for(auto &x:count){
            if(x.second > 0){
                x.second--;
                perm(n,sol + x.first,count);
                x.second++;
            }
        }

    }else{
        res.push_back(sol);
    }
}

int main(){
    int n,i,j,k;
    cin >> n >> i >> j >> k;

    map<string,int> count;
    string sol = "";
    count["A"] = i;count["B"] = j;count["C"] = k;

    perm(n,sol,count);
    cout << res.size() << endl; // print size
    for(string &s:res) cout << s << endl;

    return 0;
}