#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp = {0};
    for(int i = 1;i < 100;i++){
        if(dp[dp.size()-1] >= n - 1) break;
        int s_string = dp[dp.size()-1] + 3;
        dp.push_back(dp[dp.size()-1] + 3);
        int s = dp.size()-1;
        for(int j = 0;j < s;j++){
            dp.push_back(dp[j] + (i + 3) + s_string);
        }
    }

    if(find(dp.begin(),dp.end(),n-1) == dp.end()){
        cout << "a" << "\n";
    }else{
        cout << "g" << "\n";
    }

    return 0;
}