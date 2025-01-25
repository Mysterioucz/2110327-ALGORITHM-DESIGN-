#include <bits/stdc++.h>
using namespace std;

int r,c;

void walk(pair<int,int> pos,string res, const vector<vector< bool > > &area){
    if(pos.first == r-1 && pos.second == c-1){
        cout << res << "\n";
        return;
    }
    if(0 <= pos.second && pos.second < c-1){ // ถ้าอยู่ col ท้ายขยับไปในแกน x ไม่ได้
        if(!area[pos.first][pos.second + 1]){
            walk(make_pair(pos.first,pos.second + 1),res + "A",area);
        }
    }
    if(0 <= pos.first && pos.first <= r-1){ // ถ้าอยู่ row แรก/ท้าย สามารถขัย ลง/ขึ้น ได้
        if(pos.first < r-1 && !area[pos.first + 1][pos.second] && (res.empty() || res[res.length() - 1] != 'C')){ //able to walk up if up pos is in map and never been walked before
            walk(make_pair(pos.first + 1,pos.second),res + "B",area);
        }
        if(pos.first > 0 && !area[pos.first - 1][pos.second] && ( res.empty() || res[res.length() - 1] != 'B')){ //able to walk up if up pos is in map and never been walked before
            walk(make_pair(pos.first - 1,pos.second),res + "C",area);
        }
    }
}

int main(){
    // vector<string> sol;
    int temp;
    cin >> r >> c;
    vector<vector< bool >> area(r,vector<bool>(c,false));
    for(int i = 0;i < r;++i){
        for(int j = 0;j < c;++j){
            cin >> temp;
            if(temp == 1) area[i][j] = true;
        }
    }
    walk(make_pair(0,0),"",area);
    cout << "DONE" << "\n";
    return 0;
}
