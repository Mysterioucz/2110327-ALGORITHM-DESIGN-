#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    // Create a.size() * b.size() table which lable for subseq start with i and end with j
    vector<vector<int > > data(a.size() + 1,vector<int>((b.size() + 1),0));
    string res = "";
    for(int i = 1;i <= a.size();i++){
        for(int j = 1;j <= b.size();j++){
            if(a[i - 1] == b[j - 1]){
                data[i][j] = data[i - 1][j - 1] + 1;
                res += a[i-1];
            }else{
                data[i][j] = max(data[i][j - 1],data[i - 1][j]);
            }
        }
    }
    cout << data[a.size()][b.size()] << "\n";
    cout << res << "\n";
    
    return 0;
}