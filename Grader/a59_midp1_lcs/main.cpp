#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    string a,b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    
    for(int i = 0;i < n + 1;i++){
        for(int j = 0;j < m + 1;j++){
            cin >> dp[i][j];
        }
    }
    string res = "";
    int i = n;int j = m;
    while(dp[i][j] != 0 && i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]){ // move upper
            i--;
        }else if(dp[i][j] == dp[i][j-1]){//move to the left
            j--;
        }else if(dp[i][j] > dp[i-1][j-1]){
            res += a[i-1];
            i--;j--;
        }
    }
    
    reverse(res.begin(),res.end());
    cout << res << "\n";
    
    return 0;
}