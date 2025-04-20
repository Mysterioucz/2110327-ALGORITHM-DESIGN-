#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n),c(4,0);
    for(int i = 0;i < n;i++){ 
        cin >> v[i];
        c[v[i]]++;
    }
    int res = 0;
    int i1 = 0,i2 = c[1],i3 = c[1] + c[2]; // start index of 2,3
    for(int i = 0;i < n;i++){
        if(i < c[1]){ // 1's zone
            if(v[i] == 2){// if it is 2 swap with 2's zone
                swap(v[i],v[i2++]);
            }else if(v[i] == 3){//swap with 3 zone
                swap(v[i],v[i3++]);
            }
            res++;
        }else if(i < c[1] + c[2]){// 2's zone
            if(v[i] == 1){// if it is 1 swap with 1's zone
                swap(v[i],v[i1++]);
                
            }else if(v[i] == 3){//swap 3 with 3 zone
                swap(v[i],v[i3++]);
            }
            res++;
        }else{ // 3's zone
            if(v[i] == 1){// swap 1 with 1's zone
                swap(v[i],v[i1++]);
            }else if(v[i] == 2){//swap 2 with 2 zone
                swap(v[i],v[i2++]);
            }
            res++;
        } 
    }
    cout << res;
    return 0;
}