#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calcPrice(const vector<ll> &grass,const vector<ll> &psa,ll k,ll start,ll bud){
    ll l = start + 1;ll r = grass.size() - 1;
    while(l < r){
        ll mid = (l + r + 1)/2;
        ll cost = (psa[mid] - psa[start]) + (r-l + 1)*k;
        if(cost > bud){
            r = mid - 1;
        }else if(cost < bud){
            l = mid + 1;
        }else if(cost == bud){
            return psa[mid] - psa[start];
        }
    }
    return psa[r] - psa[start];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m,k,start,bud;
    cin >> n >> m >> k;
    vector<ll> grass(n + 1);
    vector<ll> psa(n + 1);
    psa[0] = 0;
    for(int i = 1;i < n + 1;i++){
        cin >> grass[i];
        psa[i] = psa[i-1] + grass[i];
    }
    while(m--){
        cin >> start >> bud;
        cout << calcPrice(grass,psa,k,start,bud) << "\n";
    }

    return 0;
}