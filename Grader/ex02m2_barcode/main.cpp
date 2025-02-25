#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int c = 0;

void barcode_gen(string res,int c_change,int cons){
    int tmp = (n - res.size() - (m - cons));
    if(cons > m || c_change > k || (n - res.size()) < (k - c_change) || (max(tmp,0))/max(1,(k - c_change)) > m){ // ถ้าต้องสลับสีอีก i ครั้งแต่ช่องเหลือน้อยกว่า i ก็ตัดทิ้งไปเลย
        // cout << res << "\n";
        return;
    }
    if(res.size() == n && cons <= m && c_change == k){
        c++;
        cout << res << "\n";
        return;
    }else if(res.size() < n){
        if(res.back() == '1'){
            barcode_gen(res + "1",c_change,cons + 1);
            barcode_gen(res + "0",c_change + 1,1);
        }else{
            barcode_gen(res + "1",c_change + 1,1);
            barcode_gen(res + "0",c_change,cons + 1);
        }
    }
    return;
}

int main(){
    cin >> n >> m >> k;
    barcode_gen("0",0,1);

    cout << c << "\n";

    return 0;
}