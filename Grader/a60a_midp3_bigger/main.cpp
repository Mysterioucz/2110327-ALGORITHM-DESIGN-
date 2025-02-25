#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> c(n+1);
    for(int i = 1;i < n + 1;i++) cin >> c[i];
    vector<int> dp(n+1,0);
    for(int i = 1;i < n + 1;i++){
        int left = max(0,i-3);
        int a = max(0,i-1);
        int b = max(0,i-2);
        dp[i] = max((dp[left] + c[i]),max(dp[a],dp[b]));
    }
    cout << dp[n] << "\n";
    return 0;
}