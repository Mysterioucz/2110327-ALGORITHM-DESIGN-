#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> cond;

void perm_with_cons(int len,string res,vector<bool> &used){
    if(len < n){
        for(int i = 0;i < n;i++){
            if(used[i]) continue;
            if(cond[i] != -1 && !used[cond[i]]) continue;
            used[i] = true;
            perm_with_cons(len + 1, res + to_string(i) + " ",used);
            used[i] = false;
        }
    }else cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("output.txt","w",stdout);// for large output check
    cin >> n >> m;
    cond.resize(n,-1);
    int a,b;
    while(m--){
        cin >> a >> b;
        cond[b] = a;
    }
    vector<bool> used(n,false);
    perm_with_cons(0,"",used);
    return 0;
}