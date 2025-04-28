#include <bits/stdc++.h>
using namespace std;

int x;
unordered_set<int> genCheck;

int stateS(){
    queue<pair<int,int>> q;
    int res = INT_MAX;
    q.push(make_pair(x,0));
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        if(p.first == 0){
            res = p.second;
            return res;
        }
        int a = (p.first + 1)%16777216, b = (p.first*2)%16777216;
        q.push(make_pair(a,p.second  + 1));
        q.push(make_pair(b,p.second  + 1));
    }
}

int main(){
    cin >> x;
    cout << stateS() << "\n";
    return 0;
}