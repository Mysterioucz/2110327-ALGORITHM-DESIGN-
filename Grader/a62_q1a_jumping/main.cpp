#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n+1),dp(n+1,0);
    for(int i = 1;i < n + 1;i++) cin >> p[i];
    for(int i = 1;i < n + 1;i++){
        int left = max(1,i-3);
        int candidatePoint = dp[left] + p[i];
        while(left < i){
            candidatePoint = max(candidatePoint,dp[left] + p[i]);
            left++;
        }
        dp[i] = candidatePoint;
    }
    cout << dp[n] << "\n";
    return 0;
}