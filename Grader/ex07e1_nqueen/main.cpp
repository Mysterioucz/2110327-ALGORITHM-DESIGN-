#include <bits/stdc++.h>
using namespace std;
int n,res = 0;
vector<int> pos;
vector<bool> used;

bool check(int step){
    for(int i = 0;i < step;i++){
        int curCol = pos[i];
        int ru,rl;
        for(int j = 1;j < i + 1;j++){
            ru = pos[i-j];
            if(abs(curCol - ru) == j) return false;
        }
        for(int j = 1;j < step - i;j++){
            rl = pos[i+j];
            if(abs(curCol - rl) == j) return false;
        }
    }
    return true;
}

void n_queen(int step){
    if(step < n){
        if(!check(step)) return;
        for(int i = 0;i < n;i++){
            if(!used[i]){
                pos[step] = i;
                used[i] = true;
                n_queen(step+1);
                used[i] = false;
            }
        }
    }else{
        if(check(step)) res++;
    }
}

int main(){
    cin >> n;
    pos.resize(n);
    used.resize(n);
    n_queen(0);
    cout << res;
    return 0;
}