#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &v, int num){
    int l = 0,r = v.size() - 1;
    while(l < r){
        int mid = (l + r + 1)/2;
        if(v[mid] == num) return v[mid]; // in this problem all data are distinc (ไม่ซ้ำ)
        else if(v[mid] < num) l = mid + 1;
        else if(v[mid] > num) r = mid - 1;
    }
    if(v[r] <= num) return v[r];
    if(r != 0) return v[r-1];
    return r-1;

}

int main(){
    int n,m,tmp;
    cin >> n >> m;
    vector<int> data(n);
    for(int i = 0;i < n;i++) cin >> data[i];
    while(m--){
        cin >> tmp;
        cout << binary_search(data,tmp) << "\n";
    }
    return 0;
}