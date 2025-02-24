#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> v(n + 1,0);
    vector<int> w(n + 1,0);
    for(int i = 1;i < n + 1;i++) cin >> v[i];
    for(int i = 1;i < n + 1;i++) cin >> w[i];

    vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
    for(int i = 0;i < n + 1;i++){
        for(int j = 0;j < m + 1;j++){
            cin >> dp[i][j];
        }
    }

    // row is v (val) r is number of item, col is weight 
    int r = n;int c = m;
    vector<int> res;

    while(dp[r][c] != 0 && r > 0 && c > 0){
        if(dp[r][c] == dp[r - 1][c]) r--; // if we can move up then move
        else{
            res.push_back(r);
            c -= w[r];
            r--;
        }
    }

    cout << res.size() << "\n";
    for(int i = 0;i < res.size();i++) cout << res[i] << " ";
    
    return 0;
}