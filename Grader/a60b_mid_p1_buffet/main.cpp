#include <bits/stdc++.h>
using namespace std;

int main(){
    int f,w,n;
    // ofstream testLog("log.txt"); // for debugging
    cin >> f >> w >> n;
    vector<int> food(f);
    for(int &e:food) cin >> e;
    sort(food.begin(),food.end());
    // for(int i = 0;i < f;i++) testLog << food[i] << " "; // for debugging
    // testLog << "\n"; // for debugging
    int res = 1;
    int lastBulb = *(--upper_bound(food.begin(),food.end(),food[0] + w));
    // testLog << "FirstBulb: " << lastBulb << "\n"; // for debugging
    while(food[f-1] > lastBulb + w ){
        int nextPos = *upper_bound(food.begin(),food.end(),lastBulb + w);
        // lastBulb = (--upper_bound(nextPos,food.end(),*nextPos + w));
        lastBulb = nextPos + w;
        res++;
        // testLog << lastBulb << "\n"; // for debugging
        // testLog << "Next Pos: "<< *nextPos << " lastBulb: " << lastBulb << "\n";
    }
    cout << res;
    
    return 0;
}