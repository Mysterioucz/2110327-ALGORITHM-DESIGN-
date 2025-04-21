#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k,w,totalP = 0;
    cin >> n >> m >> k >> w;
    vector<int> p(m),h(m);
    for(int i = 0;i < m;i++) cin >> p[i];
    for(int i = 0;i < m;i++) cin >> h[i];
    vector<int> v(n + 1,0);
    for(int i = 0;i < m;i++){
        v[p[i]] += h[i];
        totalP += h[i];
    }
    sort(p.begin(),p.end());
    int i = 0;
    int lastPos = max(1,p[i] - w);
    while(k > 0 && i < m){
        if((max(0,p[i] - w) <= lastPos && lastPos <= min(n,p[i] + w)) && v[p[i]] > 0){
            v[p[i]]--;
            totalP--;
            k--;
            lastPos++;
        }else{
            if(i == m-1) break;
            do{
                i++;
            }while(i < m && (p[i] == p[i - 1] || i == 0));
            lastPos = max(lastPos,p[i] - w);
        }
    }
    cout << totalP;
    return 0;
}