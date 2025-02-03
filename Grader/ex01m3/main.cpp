#include <bits/stdc++.h>
using namespace std;

long long totalCustomer(long long t,const vector<int> &chef){ // Total customer in retaurant at time t
    long long c = t == 0 ? 0:chef.size();
    for(int i = 0;i < chef.size();i++){
        c += t/chef[i]; //total customer that each seat have been serve at time t
    }
    return c;
}

long long binary_search(long long n,const vector<int> chef){
    long l = 0;long r = 1e15;
    while(l <= r){
        long long mid = (l + r + 1)/2;
        long long tmp = totalCustomer(mid,chef);
        if(tmp > n){
            r = mid - 1;
        }else if(tmp < n){
            l = mid + 1;
        }else{
            while(mid > 0 && totalCustomer(mid - 1,chef) == n){
                mid--;
            }
            return mid;
        }
    }
    return l;
}

int main(){
    int n,a,t;
    cin >> n >> a;
    vector<int> chef(n);
    for(int i = 0;i < n;i++){
        cin >> chef[i];
    }
    long long tmp;
    while(a--){
        cin >> tmp;
        if(tmp <= n) cout << "0" << "\n";
        else cout << binary_search(tmp,chef) << "\n";
    }
    return 0;
}