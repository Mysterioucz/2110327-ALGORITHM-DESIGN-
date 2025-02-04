#include <bits/stdc++.h>
using namespace std;

int min_subseq(const vector<int> &v){
    int minEnd = v[0];int res = v[0];
    for(int i = 1;i < v.size();i++){
        if(minEnd <= 0){
            minEnd += v[i];
        }else{
            minEnd = v[i];
        }
        res = min(res,minEnd);
    }
    return res < 0 ? res:0;

}

int main(){
    // MCS of Circular Subsequence is total - minSubSequence
    int n;int total = 0;
    cin >> n;
    vector<int> data(n);
    for(int i = 0;i < n;i++){
        cin >> data[i];
        total += data[i];
    }
    int res = total - min_subseq(data);
    if(res == 0) res = *max_element(data.begin(),data.end());
    cout << res << "\n";
    return 0;
}