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
            //using two pointer
            int left = i + 1;int right = data.size() - 1;
            while(left < right && !found){
                int total = data[i] + data[left] + data[right];
                if(total > tmp){
                    right--;
                }else if(total < tmp){
                    left++;
                }else{
                    found = true;
                }

            }
        }
        if(found) cout << "YES" <<"\n";
        else cout << "NO" << "\n";
    }
    return 0;
}