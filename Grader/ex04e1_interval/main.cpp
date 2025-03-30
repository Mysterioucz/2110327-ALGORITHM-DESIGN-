#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<pair<int,int>> task(n); // [{stop.start},{..},...]
    for(int i = 0;i < n;i++) cin >> task[i].second;
    for(int i = 0;i < n;i++) cin >> task[i].first;
    sort(task.begin(),task.end());

    int last = -1; // the end time of last selected task
    int c = 0;
    for(int i = 0;i < n;i++){
        if(task[i].second >= last){
            c += 1;
            last = task[i].first;
        }
    }
    cout << c << "\n";

    return 0;
}