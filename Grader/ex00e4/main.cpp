#include <bits/stdc++.h>
using namespace std;

int a,len;

void genBarcode(string res,int amount){
    if(res.size() < len){
        if(len - res.size() > a - amount) genBarcode(res + "0",amount);
        if(amount < a) genBarcode(res + "1",amount + 1);
    }else cout << res << "\n";

}
int main(){
    cin >> a >> len;
    genBarcode("",0);
    return 0;
}