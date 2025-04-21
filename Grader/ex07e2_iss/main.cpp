#include <bits/stdc++.h>
using namespace std;
int n,res = 0;

void iss(int sum,int last){
    if(sum > n) return;
    if(sum == n){
        res++;
    }else{
        for(int i  = 1;i <= n;i++){
            if(last > i) continue;
            iss(sum + i,i);
        }
    }
}

int main(){
    cin >> n;
    iss(0,0);
    cout << res;
    return 0;
}