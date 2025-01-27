#include <bits/stdc++.h>
using namespace std;

int bestSol = -1;
vector<int> p,t;
int n,m,k,w;


void gameLoop(int idx,vector<int> h){
    if(idx < k){
        for(int i = 0;i < m;i++){
            if(t[idx] - w <= p[i] && p[i] <= t[idx] + w){ // monster ตัวที่ i อยู่ในระยะยิงของป้อมที่ idx ไหม
                if(h[i] <= 0) continue; // ถ้ายิง monster ตัวที่มี hp <= 0 กรณีนี้ไม่สามารถเกิดขึ้นได้ให้ข้ามไป
                h[i]--;
            }
            gameLoop(idx + 1,h);
            if(t[idx] - w <= p[i] && p[i] <= t[idx] + w){
                h[i]++;
            }
        }
    }else{
        int total = 0;
        for(const auto &hp:h){
            total += max(0,hp);
        }
        if(bestSol == -1) bestSol = total;
        else bestSol = min(total,bestSol);
    }

}

int main(){
    // This is COP Problem
    cin >> n >> m >> k >> w;
    vector<int> h(m);
    p.resize(m);t.resize(k);
    for(auto &e:p) cin >> e;
    for(auto &e:h) cin >> e;
    for(auto &e:t) cin >> e;
    gameLoop(0,h);
    cout << bestSol;

    return 0;
}