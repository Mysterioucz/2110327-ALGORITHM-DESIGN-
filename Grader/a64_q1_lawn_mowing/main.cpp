#include <bits/stdc++.h>
using namespace std;
// using long long = long long;

long long calcPrice(const vector<long long> &grass,const vector<long long> &psa,long long k,long long start,long long bud){
    long long l = start;long long r = grass.size() - 1;
    long long cost;
    while(l < r){
        long long mid = (l + r + 1)/2;
        cost = (psa[mid] - psa[start - 1]) + (mid - start + 1)*k;
        if(cost > bud){
            r = mid - 1;
        }else if(cost < bud){
            l = mid + 1;
        }else if(cost == bud){
            return psa[mid] - psa[start - 1];
        }
    }
    cost = (psa[r] - psa[start - 1]) + (r-start + 1)*k;
    while(cost > bud && r > 0){
        r--;
        cost = (psa[r] - psa[start - 1]) + (r-start + 1)*k;
    }
    return psa[r] - psa[start - 1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n,m,k,start,bud;
    cin >> n >> m >> k;
    vector<long long> grass(n + 1);
    vector<long long> psa(n + 1);
    psa[0] = 0;
    for(int i = 1;i < n + 1;i++){
        cin >> grass[i];
        psa[i] = psa[i-1] + grass[i];
    }
    while(m--){
        cin >> start >> bud;
        cout << calcPrice(grass,psa,k,start + 1,bud) << "\n";
    }

    return 0;
}