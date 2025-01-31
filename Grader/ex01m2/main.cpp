#include <bits/stdc++.h>
using namespace std;


int merge(){

    return 0;
}

void merge_sort(vector<int> &v,int start, int stop,vector<int> &tmp){

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    // need to solve using merge sort
    int n,tmp;
    cin >> n;
    vector<int> data(n);
    for(int i = 0;i < n;i++){
        cin >> data[i];
    }
    // sort(data.begin(),data.end());
    int ans = 0;
    for(int i = 0;i < data.size() - 1;i++){
        for(int j = i+1;j < data.size();j++){
            if(data[i] > data[j]) ans++;
        }
    }
    
    cout << ans;

    return 0;
}