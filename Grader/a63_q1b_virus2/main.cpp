#include <bits/stdc++.h>
using namespace std;

int isVirus(const vector<int> &v,int start,int stop,bool &res){
    if(stop - start == 1){
        return v[start] + v[stop];
    }

    int mid = (start + stop)/2;
    int a = isVirus(v,start,mid,res);
    int b = isVirus(v,mid + 1,stop,res);
    if(a == -1 || b == -1) return -1;

    if(abs(a-b) > 1){
        res = false;
        return -1;
    }
    return a + b;

}

int main(){
    int n,k;int amount = 1;
    cin >> n >> k;
    for(int i = 0;i < k;i++){
        amount *= 2;
    }
    while(n--){
        vector<int> data(amount);
        for(int i = 0;i < amount;i++){
            cin >> data[i];
        }
        bool res = true;
        isVirus(data,0,data.size() - 1,res);
        if(res) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    

    return 0;
}