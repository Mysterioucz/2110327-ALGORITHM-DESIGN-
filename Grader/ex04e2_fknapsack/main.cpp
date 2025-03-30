#include <bits/stdc++.h>
using namespace std;

int n;
double w;
vector<double> v;
vector<double> item_w;
double res;

void frac_knapsack(int idx, vector<double> &pick, double remain, double total){
    if(idx == -1|| remain == 0){
        res = total;
        return;
    }
    if(remain >= item_w[idx]){
        pick[idx] = 1;
        frac_knapsack(idx-1,pick,remain - item_w[idx],total + v[idx]);
    }else{
        pick[idx] = remain/item_w[idx];
        frac_knapsack(idx-1,pick,0,total + pick[idx]*v[idx]);
    }
}

int main(){
    cin >> w >> n;
    v.resize(n);
    item_w.resize(n);
    for(int i = 0;i < n;i++) cin >> v[i];
    for(int i = 0;i < n;i++) cin >> item_w[i];

    vector<vector<double>> item(n);
    for(int i = 0;i < n ;i++){
        item[i] = {v[i]/item_w[i],v[i],item_w[i]};
    }
    sort(item.begin(),item.end());
    for(int i = 0;i < n ;i++){
        v[i] = item[i][1];
        item_w[i] = item[i][2];
    }
    vector<double> pick(n,0);
    frac_knapsack(n-1,pick,w,0.0);

    printf("%.4f",res);

    return 0;
}