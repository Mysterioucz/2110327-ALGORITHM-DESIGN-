#include <bits/stdc++.h>
using namespace std;

int tCount,n;
vector<vector<double>> m;

bool bellman_ford(int a){
    vector<double> cost(n,-1e9);
    cost[a] = 1;
    for(int _ = 0;_ < n-1;_++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                if(cost[j] < cost[i] + log(m[i][j])){
                    cost[j] = cost[i] + log(m[i][j]);
                }
            }
        }
    }
    for(int _ = 0;_ < n-1;_++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                if(cost[j] < cost[i] + log(m[i][j])){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> tCount;
    for(int _ = 0;_ < tCount;_++){
        cin >> n;
        m.clear();
        m.resize(n,vector<double>(n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cin >> m[j][i];
            }
        }
        if(bellman_ford(0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}