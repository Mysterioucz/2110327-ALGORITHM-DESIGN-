#include <bits/stdc++.h>
using namespace std;

int n,m,k,res = INT_MAX/2;
vector<int> d; 
vector<int> chosen,psa;

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
        if(min(abs(total + (psa[n-1] - psa[(n - (m - chosen.size())) - 1]) - k),abs(total + (psa[step + ( m - chosen.size()) - 1] - psa[step - 1]) - k)) > res) return; // min(max_heu,min_heu)
        // if(abs(total + heuristic(step,abs(k - total)) - k) > res) return; // heuristic because we sort the data so we can use this
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
    psa.resize(n);
    for(int i = 0;i < n;i++) cin >> d[i];
    sort(d.begin(),d.end());
    for(int i = 0;i < n;i++){
        psa[i] = i==0? d[0]:d[i] + psa[i-1];
    }
    stateS(0,0);
    cout << res << "\n";
    return 0;
}