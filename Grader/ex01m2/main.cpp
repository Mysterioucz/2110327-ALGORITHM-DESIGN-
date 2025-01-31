#include <bits/stdc++.h>
using namespace std;

int count_inversion(const vector<int> &a,const vector<int> &b){
    int ans = 0;
    for(int i = 0;i < a.size();i++){
        int j = 0;
        while(j < b.size() && a[i] > b[j]){
            j++;
        }
        ans += j;
    }

    return ans;
}

int main(){

    // cout << count_inversion({9},{1,2,3,4,5});
    // need to solve using merge sort
    unordered_map<int,vector<int>> idx;
    vector<int> data;

    int n,tmp;
    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> tmp;
        if(!idx.count(tmp)){
            data.push_back(tmp);
        }
        idx[tmp].push_back(i);
    }
    sort(data.begin(),data.end());

    int aj = 0;int ans = 0;
    while(aj < data.size() - 1){
        for(int ai = aj + 1;ai < data.size();ai++){
        ans += count_inversion(idx[data[aj]],idx[data[ai]]);
        }
        aj++;
    }
    cout << ans;

    return 0;
}