#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &v, int num){
    int l = 0;int r = v.size() - 1;
    while(l < r){
        int mid = (l + r + 1)/2;
        if(v[mid] > num){
            r = mid - 1;
        }else if(v[mid] < num){
            l = mid + 1;
        }else {
            while(mid + 1 < v.size() && v[mid+1] == num ){
                mid++;
            }
            return mid;
        }
    }
    if(v[r] <= num) return r;
    return r-1;
    

}

int main(){
    int n,m,tmp;
    cin >> n >> m;
    vector<int> data(n);
    for(int &e:data) cin >> e;
    while(m--){
        cin >> tmp;
        cout << binary_search(data,tmp) << "\n";
    }
    return 0;
}