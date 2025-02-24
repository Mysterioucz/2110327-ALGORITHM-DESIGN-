#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> dp(3,0);
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3;i < 1e6;i++){
        auto it = (lower_bound(dp.begin(),dp.end(),i));
        long long idx = (it - dp.begin());
        dp.push_back(dp[i-1] + idx);
    }
    while(n--){
        long long tmp;
        cin >> tmp;
        cout << lower_bound(dp.begin(),dp.end(),tmp) - dp.begin() << "\n";
    }
    // cout << dp[3] << ", " << dp[4] << ", " << dp[5];
    return 0;
}