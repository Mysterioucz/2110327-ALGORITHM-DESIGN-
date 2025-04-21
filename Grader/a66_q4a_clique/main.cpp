#include <bits/stdc++.h>
using namespace std;

int n,res = 0;
vector<int> b,psa,idx;
vector<vector<int>> f;
vector<int> used;

bool check(){
    if(used.size() == 0) return true;
    int i = used.back();
    for(int j = 0;j < used.size()-1;j++){
        if(( f[i][used[j]] == 0||f[used[j]][i] == 0)) return false;// return false when i,j is in same team but one of them don't know each order
    }
    return true;
}

void clique(int step,int sum){
    if(step < n){
        if(!check()) return;
        if(res > sum + (psa[n-1] - psa[step-1])) return;
        used.push_back(idx[step]);
        clique(step + 1,sum + b[idx[step]]);
        used.pop_back();
        clique(step + 1,sum);
    }else{
        if(check()) res = max(res,sum);
    }
}

int main(){
    // cin.tie(null);
    cin >> n;
    b.resize(n);
    psa.resize(n);
    f.resize(n,vector<int>(n));
    for(int i = 0;i < n;i++){
        cin >> b[i];
        idx.push_back(i);
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> f[i][j];
        }
    }

    sort(idx.begin(),idx.end(),[](const int &x,const int &y){
        return b[x]>b[y];
    });
    for(int i = 0;i < n;i++){
        psa[i] = i == 0 ? b[idx[i]]: b[idx[i]] + psa[i-1];
    }

    clique(0,0);
    cout << res;
    return 0;
}