#include <bits/stdc++.h>
using namespace std;

int n,m,k,res = INT_MAX/2;
vector<int> d; 
vector<int> chosen;

int heuristic(int step,int target){
    int sum = 0;
    auto it = lower_bound(d.begin() + step,d.end(),target);
    while(sum < target){
        it = lower_bound(d.begin() + step,d.end(),target - sum);
        if(it == d.begin()) return sum;
        it--;
        sum += *it;
        
    }
    return sum > target ? sum - *it:sum;
}

void stateS(int step,int total){
    if(chosen.size() < m && step < n){
        if(chosen.size() + (n - step) + 1 < m) return; // backtracking
        if(abs(total + d[step] - k) > res) return; // this heuristic is better than the on below
        if(abs(total + heuristic(step,abs(k - total)) - k) > res) return; // heuristic because we sort the data so we can use this
        chosen.push_back(d[step]);
        stateS(step + 1,total + d[step]);
        chosen.pop_back();
        stateS(step + 1,total);
    }else{
        if(chosen.size() == m)res = min(res,abs(k-total));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    d.resize(n);
    for(int i = 0;i < n;i++) cin >> d[i];
    sort(d.begin(),d.end());
    stateS(0,0);
    cout << res << "\n";
    return 0;
}