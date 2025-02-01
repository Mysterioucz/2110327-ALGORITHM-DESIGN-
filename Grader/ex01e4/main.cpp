#include <bits/stdc++.h>
using namespace std;

long long mod_expo(int x, int n, int k){
    // from lecture that (a * b) % k = ((a % k) * (b % k)) % k
    if(n == 1){
        return x%k;
    }else if(n%2 == 0){
        long long tmp = mod_expo(x,n/2,k);
        return (tmp * tmp) % k;
    }else{
        long long tmp = mod_expo(x,n/2,k);
        tmp = (tmp * tmp) % k;
        return (tmp * (x % k)) % k;
    }
}

int main(){
    int x,n,k;
    cin >> x >> n >> k;
    cout << mod_expo(x,n,k);
}