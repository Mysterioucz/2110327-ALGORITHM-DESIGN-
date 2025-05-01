#include <bits/stdc++.h>
using namespace std;

int n,k,res = INT_MIN/2;
vector<int> c;
string f = "";

int heuristic(int s, int score){
    vector<int> dp(n-s + 1,0);
    for(int i = 1;i < n - s + 1;i++){
       if(i == 1) dp[i] = c[i + s - 1];
       else dp[i] = max(dp[i-2] + c[i + s - 1],dp[i-1]);
    }
    return dp.back() + score;
}

void stateS(string sol,int score){
    if(sol.size() >= f.size()){
        if(sol.substr(sol.size() - f.size(),f.size()) == f) return;
    }
    if(sol.size() == n){
        res = max(res,score);
    }else{
        if(heuristic(sol.size(),score) <= res) return;
        if(sol.back() != '1') stateS(sol + "1",score + c[sol.size()]);
        stateS(sol + "0",score);
    }
}

int main(){
    cin >> n >> k;
    c.resize(n);
    for(int i = 0;i < n;i++) cin >> c[i];
    for(int i = 0;i < k;i++){
        int tmp;
        cin >> tmp;
        f += to_string(tmp);
    }
    stateS("",0);
    cout << res << "\n";
    return 0;
}