#include <bits/stdc++.h>
using namespace std;

vector<int> pareto(int l,int r,const vector<pair<int,int>> &v){ // Vector v need to be sorted by X Cord
    vector<int> res;
    if(r - l == 1){
        if(v[r].first > v[l].first && v[r].second > v[l].second){
            res.push_back(l);
        }else if(v[r].first < v[l].first && v[r].second < v[l].second){
            res.push_back(r);
        }
        return res;
    }

    int mid = (l + r)/2;
    vector<int> paretoLeft = pareto(l,mid,v);
    vector<int> paretoRight = pareto(mid + 1,r,v);
    

}

int main(){

    return 0;
}