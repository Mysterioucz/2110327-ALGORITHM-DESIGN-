#include <bits/stdc++.h>
using namespace std;

vector<int> p,seq;
vector<int> psa;
int a,b,totalCost = 0;

int shortest_path(int x,int y){
    if(y<x) swap(x,y);
    int costCW = abs(psa[y]-psa[x]);
    int costCCW = totalCost - costCW;
    // if(y<x){
    //     swap(costCW,costCCW);
    // }
    if(x<= a && b <= y) costCW -= p[a];
    else costCCW -= p[a];
    return min(costCW,costCCW); // cost when go clock-wise and coutner-clock-wise
}

int main(){
    int n,m;
    cin >> n >> m;
    seq.resize(m);
    p.resize(m);
    psa.resize(m);
    for(int &e:seq) cin >> e;
    for(int &e:p){
        cin >> e;
        totalCost += e;
    }
    psa[0] = 0;
    for(int i = 1;i < m;i++){
        psa[i] = psa[i-1] + p[i-1];
    }
    for(int _ = 0;_ < n;_++){
        int cost = 0;
        cin >> a >> b;
        for(int i = 0;i < m;i++){
            cost += shortest_path(seq[i],seq[(i+1)%m]);
        }
        cout << cost << "\n";
    }
    
    return 0;
}