#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1); // dp[i] คือจำนวนรุปแบบที่เป็นไปได้ของความยาว i
    dp[0] = 0;
    dp[1] = 3;
    dp[2] = 7;
    for(int i = 3;i < n + 1;i++){
        dp[i] = (2*dp[i-1] + (i <=3 ? 1:dp[i-3]))%(100000007);
    }

    cout << dp[n] << "\n";
    return 0;
}