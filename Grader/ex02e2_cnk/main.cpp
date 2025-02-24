#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1,vector<int>(k + 1));
    // for(int i = 0;i < n+1;i++) dp[i][0] = 1; // when k == 0
    // for(int i = 0;i < min(n+1,k+1);i++) dp[i][i] = 1; // when n == k
    for(int i = 0;i < n + 1;i++){
        for(int j = 0;j < min(i + 1,k + 1);j++){
            if(j == 0 || i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    cout << dp[n][k] << "\n";


    return 0;
}