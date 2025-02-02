#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> startPos;
    vector<int> data(n);
    vector<int> s(n);
    s[0] = 0;
    for(int i = 0;i < n;i++){
        cin >> data[i];
        if(!startPos.count(data[i])) startPos[data[i]] = i;
        if(i == 0)s[i] = data[i];
        else s[i] = (s[i - 1] + data[i]);
    }
    int res = data[0]; // the problem guarantee that n >= 1
    for(int i = 0;i < n;i++){
        if(s[i] < s[startPos[data[i]]]) startPos[data[i]] = i;
        res = max(s[i] - s[startPos[data[i]] - 1],res);
    }
    cout << res << "\n";

    return 0;
}