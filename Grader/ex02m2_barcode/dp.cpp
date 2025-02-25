#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,c;
    cin >> n >> m >> c;

    vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(m + 1,vector<int>(c + 1,0)));
    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < m + 1;j++){
            // initial condition of recurrence relation
            if(i <= j) dp[i][j][0] = 1;
        }
    }
    // dp[1][1][0] = 1;
    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < m + 1;j++){
            for(int k = 1;k < c + 1;k++){
                // initial condition of recurrence relatio
                if(i - j == k){
                    dp[i][j][k] = dp[i-1][j-1][k] + dp[i-1][j][k-1];
                }else {
                    dp[i][j][k] = dp[i][j-1][k];
                }
                
            }
        }
    }
    for(int i = 0;i < n + 1;i++){
        for(int j = 0;j < m + 1;j++){
            for(int k = 0;k < c + 1;k++){
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << dp[n][m][c] << "\n";
    return 0;
}