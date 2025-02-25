#include <bits/stdc++.h>
using namespace std;

map<int,int> memo;

int dp(int l){
    if(memo.find(l) != memo.end()) return memo[l];
    memo[l] = (2*dp(l-1) + (l <= 3 ? 1:dp(l-3)))%100000007;
    return memo[l];
}

int main(){
    int n;
    cin >> n;
    memo[1] = 3;memo[2] = 7;
    cout << dp(n);
    return 0;
}