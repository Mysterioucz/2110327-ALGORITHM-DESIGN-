#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> data(n);
    for(int &e:data) cin >> e;
    int k;
    while(m--){
        cin >> k;
        int c = 0;
        for(int i = 0;data[i] != k;i++){
            if(data[i] > k) c++;
        }
        cout << c << "\n";
    }
    return 0;
}