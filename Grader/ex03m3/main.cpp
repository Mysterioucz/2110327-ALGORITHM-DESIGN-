#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> data(n + 1);
    for(int i = 1;i < n + 1;i++){
        cin >> data[i];
    }

    vector<int> dp(n + 1,2e9);
    dp[0] = 0;
    for(int i = 1;i < n + 1;i++){
        int left = max(1,i - k); // using min/max for boundary
        int right = min(n, i + k);

        int new_cost = dp[left - 1] + data[i];
        for(int j = left;j < right + 1;j++){
            dp[j] = min(dp[j], new_cost); // dp[j] can be segment that not pressure regulated yet or be the segment that is already regulated
            // if dp[j] is already regulated zone and that segment is more expensive than if we put station here then we replace the station
            // if dp[j] is more expensive but there segment that i<left that is regulated by previous station then we do nothing by including dp[left - 1] in new_cost
        }
    }
    cout << dp[n] << "\n";
    return 0;
}