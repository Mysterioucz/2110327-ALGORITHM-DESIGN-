#include <bits/stdc++.h>
using namespace std;

int calc_sum(int x){
    return (x + 1)*x/2;
}

int main(){
    int l;
    cin >> l;
    int n = calc_sum(l);
    vector<int> data(n + 1,0);
    vector<vector<int>> dp(l + 1,vector<int>(l + 1));
    for(int i = 1;i < n + 1;i++) cin >> data[i];
    dp[1][1] = data[1];
    for(int i = 1;i < l + 1;i++){
        for(int j = 1;j <= i;j++){
            int cur_val = data[calc_sum(i - 1) + j];
            if(j == 1) dp[i][j] = dp[i - 1][j] + cur_val;
            else if(i == j) dp[i][j] = dp[i - 1][j - 1] + cur_val;
            else{
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + cur_val;
            }
        }
    }
    cout << *max_element(dp[l].begin(),dp[l].end()) << "\n";
    return 0;
}