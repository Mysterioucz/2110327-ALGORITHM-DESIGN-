#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    vector<int> camp(n);
    for(int i = 0;i < n;i++) cin >> camp[i];
    int k = (camp[n-1] + d - 1)/(d); // this is the least amount of K that are possible
    int lastCamp = 0;
    while(lastCamp + k < camp[n-1]){
        auto tmp = upper_bound(camp.begin(),camp.end(),lastCamp + k);
        auto tmp2 = tmp;
        if(tmp == camp.begin() || *(--tmp2) == lastCamp){
            //this mean current K value can't climb to next camp
            // update K with least k that need to use to climb to next camp
            k = *upper_bound(camp.begin(),camp.end(),lastCamp) - lastCamp;
        
        }else{// Current K is possible to climb to next camp
            tmp--;
            lastCamp = *tmp;
        }   
    }
    int day;
    while(true){
        lastCamp = 0;
        day = 0;
        while(lastCamp != camp[n-1]){
            auto tmp = --upper_bound(camp.begin(),camp.end(),lastCamp + k);
            lastCamp = *tmp;
            day++;
        }
        if(day <= d) break;
        else k += 1;
    }
    
    cout << k << " " << day;
    return 0;
}