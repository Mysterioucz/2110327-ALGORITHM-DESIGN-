#include <bits/stdc++.h>
using namespace std;

bool compX(const pair<int,int> &a,const pair<int,int> &b){
    return a.first < b.first;
}
bool compY(const pair<int,int> &a,const pair<int,int> &b){
    return a.second < b.second;
}

int main(){
    int n,x,y;
    cin >> n;
    vector<pair<int,int>> data;
    for(int i = 0;i < n;i++){
        cin >> x >> y;
        data[i] = make_pair(x,y);
    }
    
    return 0;
}