#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<double> v(m);
    vector<double> t(n,0);
    for(auto &e:v) cin >> e;
    
    sort(v.begin(),v.end());
    double total = 0;
    for(int i = 0;i < v.size();i++){
        t[i%n] += v[i];
        total += t[i%n];
    }
    printf("%.3f",total/m);
    return 0;
}