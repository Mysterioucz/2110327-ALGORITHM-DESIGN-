#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> s(k + 1);
    for(int i = 1;i < k + 1;i++) cin >> s[i];
    sort(s.begin(),s.end());
    vector<int> dp(n + 1,0);
    dp[1] = 1;
    for(int i = 2;i < n + 1;i++){
        for(int j = 1;j < k + 1;j++){
            if(s[j] <= i){
                dp[i] = (dp[i] + (dp[i-s[j]] + (i==s[j])) % 1000003) % 1000003;
            }
        }
        // dp[i] = dp[i] % 1000003;
    }

    cout << dp[n];
    return 0;
}