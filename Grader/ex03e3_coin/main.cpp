#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> coin(n + 1,0);
    vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
    for(int i = 1;i < n + 1;i++) cin >> coin[i];
    sort(coin.begin(),coin.end());

    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < m + 1;j++){
            if(coin[i] > j) dp[i][j] = dp[i-1][j];
            else{
                if(dp[i - 1][j] == 0){
                    dp[i][j] =dp[i][j - coin[i]] + 1;
                }else{
                    dp[i][j] = min(dp[i][j - coin[i]] + 1,dp[i - 1][j]);
                }
            }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}