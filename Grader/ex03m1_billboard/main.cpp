#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n + 1,0);
    vector<int> dp(n + 1,0);
    for(int i = 1;i < n + 1;i++) cin >> p[i];
    for(int i = 1;i < n + 1;i++){
        int left = max(0,i - 2);
        dp[i] = max(dp[i-1],dp[left] + p[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}