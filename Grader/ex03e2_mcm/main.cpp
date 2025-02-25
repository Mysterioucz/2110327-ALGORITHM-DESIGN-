#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dm(n+1);
    vector<vector<int>> dp(n+1,vector<int>(n+1,1e7));
    for(int i = 1;i < n + 1;i++) dp[i][i] = 0;
    for(int i = 0;i < n + 1;i++) cin >> dm[i];
    for(int i = 0;i < n - 1;i++){
        int c = 2 + i;
        int r = 1;
        while(r < n + 1 && c < n + 1){
            int tmp_c = r;
            int tmp_r = r + 1;
            while(tmp_c < c && tmp_r <= c){
                int cost;
                cost = dm[r - 1]*dm[tmp_r - 1]*dm[c]; // ลบ 1 เพราะลำดับ a เริ่มที่ 0
                
                dp[r][c] = min(dp[r][tmp_c] + dp[tmp_r][c] + cost, dp[r][c]);
                tmp_c++;
                tmp_r++;
            }
            r++;c++;
        }
    }
    // for(int i = 0;i < n + 1;i++){
    //     for(int j = 0;j < n + 1;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[1][n] << "\n";
    return 0;
}