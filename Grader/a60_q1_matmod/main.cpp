#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vi;

vi mul_mat_2(vi v1,vi v2){
    vi res(2,vector<int>(2));
    res[0][0] = v1[0][0]*v2[0][0] + v1[0][1]*v2[1][0];
    res[0][1] = v1[0][0]*v2[0][1] + v1[0][1]*v2[1][1];
    res[1][0] = v1[1][0]*v2[0][0] + v1[1][1]*v2[1][0];
    res[1][1] = v1[1][0]*v2[0][1] + v1[1][1]*v2[1][1];
    return res;
}

vi mat_mod_k(vi v,int k){
    for(auto &r:v){
        for(auto &c:r){
            c %= k;
        }
    }
    return v;
}

vi mod_expo(vi v,int n,int k){
    if(n == 1){
        return mat_mod_k(v,k);
    }else if(n % 2 == 0){
        vi tmp = mod_expo(v,n/2,k);
        return mat_mod_k(mul_mat_2(tmp,tmp),k);
    }else if(n % 2 == 1){
        vi tmp = mod_expo(v,n/2,k);
        tmp = mat_mod_k(mul_mat_2(tmp,tmp),k);
        return mat_mod_k(mul_mat_2(tmp,mat_mod_k(v,k)),k);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    vi v(2,vector<int>(2));
    for(auto &r:v){
        for(auto &c:r){
            cin >> c;
        }
    }
    vi res = mod_expo(v,n,k);
    for(auto &r:res){
        for(auto &c:r){
            cout << c << " ";
        }
    }
    return 0;
}