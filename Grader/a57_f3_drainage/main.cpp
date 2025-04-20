#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    vector<int> h(n);
    for(int &e:h) cin >> e;
    sort(h.begin(),h.end());

    int lastBar = h[0]; // เก็บตน.เริม่ของแผ่นเหล็กล่าสุด
    int res = 1;
    while(lastBar + l < h[n-1]){
        lastBar = *upper_bound(h.begin(),h.end(),lastBar + l - 1);
        res++;
    }
    cout << res;
    return 0;
}