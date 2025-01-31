#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, tmp;
    cin >> n >> m;
    vector<int> data(n);
    for(int i = 0;i < n;i++){
        cin >> data[i];
    }
    while(m--){
        cin >> tmp; 
        bool found = false;
        for(int i = 0;i < data.size() && !found;i++){
            if(data[i] >= tmp) break;
            for(int j = i + 1;j < data.size() && !found;j++){
                if(data[i] + data[j] >= tmp) break;
                for(int k = j + 1;k < data.size() && !found;k++){
                    if(data[i] + data[j] + data[k]> tmp) break;
                    else if(data[i] + data[j] + data[k] == tmp) found = true;
                }
            }
        }
        if(found) cout << "YES" <<"\n";
        else cout << "NO" << "\n";
    }
    return 0;
}