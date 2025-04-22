#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int,int> c;
    for(int i = 0;i < n;i++){ 
        cin >> v[i];
        c[v[i]]++;
    }
    int res = 0,j = c[1];
    for(int i = 0;i < c[1];i++){
        if(v[i] == 2){ // scan for 2 in 1's zone and swap
            while(v[j] != 1) j++;
            swap(v[i],v[j]);
            res++;
        }
    }
    for(int i = 0;i < c[1];i++){
        if(v[i] == 3){ // scan for 3 in 1's zone and swap
            while(v[j] != 1) j++;
            swap(v[i],v[j]);
            res++;
        }
    }
    j = c[1] + c[2]; // update j to able to find 2 in 3's zone
    for(int i = c[1];i < c[1] + c[2];i++){
        if(v[i] != 2){ // scan for 3 in 2's zone and swap
            while(v[j] != 2) j++;
            swap(v[i],v[j]);
            res++;
        }
    }

    cout << res;
    // cout << "\n" << c[1] << " " << c[2] << " " << c[3] << "\n";
    // for(int i = 0;i < n;i++){
    //     if(i < c[1] && v[i] != 1) cout << "1's Failed\n";
    //     else if( i >= c[1] && i < c[1] + c[2] && v[i] != 2) cout << "2's Failed\n ";
    //     else if( i >= c[1] + c[2] && v[i] != 3) cout << "3's Failed\n";
    // }
    // for(int i = 0;i < n;i++){
    //     cout << v[i] << " ";
    // }
    return 0;
}