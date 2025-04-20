#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,int>> day(k); // <event,plant or store>
    for(int i = 0;i < k;i++){
        int d,e,l;
        cin >> d >> e >> l;
        day[d-1] = {e,l};
    }
    queue<int> q; // collect longest waiting store
    queue<int> stock; // collect earlist plant
    for(pair<int,int> p:day){
        if(p.first){ // if event is 1,B
            if(stock.empty()){
                q.push(p.second);
                cout << 0 << "\n";
            }else{
                cout << stock.front() << "\n";
                stock.pop();
            }
        }else{ // if event is 0,A
            if(q.empty()){
                stock.push(p.second);
                cout << 0 << "\n";
            }else{
                cout << q.front() << "\n";
                q.pop();
            }
        }
    }
    
    return 0;
}