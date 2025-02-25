#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1,vector<int>(k + 1,0));
    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < k + 1;j++){
            if(k == 1||i==j) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + (j*dp[i-1][j]) % 1997) % 1997;
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}