#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n,vector<int>(n));
    vector<int> deg(n-1,0);
    int maxDeg = 0;
    for(int i = 0;i < n;i++){
        int c = 0;
        for(int j = 0; j < n;j++){
            cin >> g[i][j];
            c += g[i][j];
        }
        maxDeg = c > maxDeg ? c:maxDeg;
        deg[c] += 1;
    }

    for(int i = 0;i < maxDeg + 1;i++) cout << deg[i] << " ";


    return 0;
}