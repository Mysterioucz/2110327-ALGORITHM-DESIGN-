#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> data(n+1);
    for(int i = 1;i < n + 1;i++){
        cin >> data[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> b = data;
    sort(b.begin(),b.end());
    for(int i = 1;i < n + 1;i++){ // i is row = b
        for(int j = 1;j < n + 1;j++){ // j is col = data
            if(b[i] == data[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1; // if current number of b and data is equal then we can put it in current subseq
            }else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}