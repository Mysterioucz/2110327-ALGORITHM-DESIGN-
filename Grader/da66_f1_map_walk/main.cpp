#include <bits/stdc++.h>
using namespace std;

int r,c;
void walk(pair<int,int> pos,string res,vector<string> &sol,const vector<vector<int>> &map){
    if(pos.first == r-1 && pos.second == c-1){
        sol.push_back(res);
        return;
    }
    if(0 <= pos.second && pos.second < c-1){ // ถ้าอยู่ col ท้ายขยับไปในแกน x ไม่ได้
        if(!map[pos.first][pos.second + 1]){
            walk({pos.first,pos.second + 1},res + "A",sol,map);
        }
    }
    if(0 <= pos.first && pos.first <= r-1){ // ถ้าอยู่ row แรก/ท้าย สามารถขัย ลง/ขึ้น ได้
        if(pos.first > 0 && !map[pos.first - 1][pos.second] && ( res.empty() || res[res.length() - 1] != 'B')){ //able to walk up if up pos is in map and never been walked before
            walk({pos.first - 1,pos.second},res + "C",sol,map);
        }
        if(pos.first < r-1 && !map[pos.first + 1][pos.second] && (res.empty() || res[res.length() - 1] != 'C')){ //able to walk up if up pos is in map and never been walked before
            walk({pos.first + 1,pos.second},res + "B",sol,map);
        }
    }
}

int main(){
    vector<string> sol;
    cin >> r >> c;
    vector<vector<int>> map(r,vector<int>(c));
    for(auto &row:map){
        for(auto &col:row){
            cin >> col;
        }
    }
    if (!map[0][0]) {
        walk(make_pair(0,0),"",sol,map);
    }
    for(const auto &res:sol){
        cout << res << "\n";
    }
    cout << "DONE" << "\n";
    return 0;
}
