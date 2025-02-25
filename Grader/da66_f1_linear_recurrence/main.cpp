#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,n;
    cin >> k >> n;
    vector<int> c(k+1),a(k);
    for(int i = 1;i < k + 1;i++) cin >> c[i];
    for(int i = 0;i < k;i++) cin >> a[i];

    vector<int> dp(n+1);
    for(int i = 0;i < k;i++) dp[i] = a[i];
    for(int i = k;i < n + 1;i++){
        for(int j = 1;j < k + 1;j++){
            dp[i] += (c[j]*dp[i-j])%32717;
        }
        dp[i] = dp[i]%32717;
    }
    cout << dp[n]%32717 << "\n";
    return 0;
}