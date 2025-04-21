#include <bits/stdc++.h>
using namespace std;
int n;
double max_w,res = 0;
vector<double> v,w,psa;

double heuristic(int i,double totalSpace){
    double sum = 0;
    for(int j = i;j < n;j++){
        if((max_w - totalSpace) >= w[j]){
            sum += v[j];
            totalSpace += w[j];
        }else return sum;
    }
    return sum; 
}

void knapsack(int i,double totalValue,double totalSpace){
    // Back Tracking
    if(totalSpace > max_w) return;
    // branch and bound
    if(res > totalValue + heuristic(i,totalSpace)) return;
    if(i < n + 1){
        if(max_w - totalSpace > w[i]) knapsack(i+1,totalValue + v[i],totalSpace + w[i]);
        knapsack(i+1,totalValue,totalSpace);
    }else{
        if(totalSpace <= max_w)res = max(res,totalValue);
        return;
    }
}

int main(){
    cin >> max_w >> n;
    v.resize(n+1);
    w.resize(n+1);
    psa.resize(n+1,0);
    for(int i = 1;i < n + 1;i++) cin >> v[i];
    for(int i = 1;i < n + 1;i++) cin >> w[i];
    vector<vector<double>> tmp;
    for(int i = 1;i < n + 1;i++){
        tmp.push_back({v[i],w[i]});
    }
    sort(tmp.begin(), tmp.end(), [](const vector<double>& a, const vector<double>& b) {
        return (a[0] / a[1]) > (b[0] / b[1]);
    });
    for(int i = 0;i < n;i++){
        v[i + 1] = tmp[i][0];
        w[i + 1] = tmp[i][1];
        psa[i + 1] = v[i + 1] + psa[i];
    }
    knapsack(1,0,0);
    printf("%.4f",res);
    return 0;
}