#include <bits/stdc++.h>
using namespace std;

int n,k;
void genBit(string res,int amount,int max_amount){
    if(res.size() < n){
        if(n - res.size() > k || max_amount >= k) genBit(res + "0",0,max_amount);
        if(res[res.size() - 1] == '1')genBit(res + "1",amount + 1,max(max_amount,amount + 1));
        else genBit(res + "1",1,max(1,max_amount));
    }else{
        cout << res << "\n";
    }
}

int main(){
    cin >> n >> k;
    genBit("",0,0);
    return 0;
}