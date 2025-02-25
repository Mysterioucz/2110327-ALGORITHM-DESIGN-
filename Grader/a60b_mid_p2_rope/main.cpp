#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> r(4,0);
    cin >> n;
    for(int i = 1;i < 4;i++) cin >> r[i];
    sort(r.begin(),r.end());
    vector<vector<int>> dp(4,vector<int>(n+1,0));
    for(int j = 1;j < n + 1;j++) dp[0][j] = -1e9;
    for(int i = 1;i < 4;i++){
        for(int j = 1;j < n + 1;j++){
            if(r[i] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-r[i]] + 1);
            }
        }
    }
    // for(int i = 0;i < 4;i++){
    //     for(int j = 0;j < n + 1;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[3][n] << "\n";
    return 0;
}