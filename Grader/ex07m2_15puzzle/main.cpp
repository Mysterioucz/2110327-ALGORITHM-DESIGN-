#include <bits/stdc++.h>
using namespace std;

int x,y;
int res = 50;
vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
unordered_map<string,bool> visited;


bool check_generated(const vector<vector<int>> &b){
    string s = "";
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            s += to_string(b[i][j]);
        }
    }
    if(visited.count(s) == 0){
        visited[s] = true;
        return true;
    }
    return false;
}

int manhotton(int i,int j, vector<vector<int>> &b){
    int row = abs(((b[i][j] - 1)/4) - i);
    int col = abs((b[i][j] - 1)%4 - j);
    return row + col; // row misplaced + col misplaced
}

int heuristic(pair<int,int> curPos,pair<int,int> nextPos, vector<vector<int>> b){
    swap(b[curPos.first][curPos.second],b[nextPos.first][nextPos.second]);
    int wrong = 0;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(b[i][j] == 0) continue;
            wrong += manhotton(i,j,b); 
        }
    }
    swap(b[curPos.first][curPos.second],b[nextPos.first][nextPos.second]);
    return wrong;
}

bool check(vector<vector<int>> &b){
    int num = 1;
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(num == 16) continue;;
            if(b[i][j] != num) return false;
            num++;
        }
    }
    return true;
}

struct Comparator {
    bool operator()(const pair<int, pair<int,int>>& p1, const pair<int, pair<int,int>>& p2) {
        return p1.first > p2.first;
    }
};

void puzz(int step, vector<vector<int>> &b,pair<int,int> curPos){ 
    if(check(b)){
        res = min(res,step);
    }else{
        if(step + heuristic(curPos,curPos,b) > res) return;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, Comparator> candPos; // minHeap
        for(int i = 0;i < 4;i++){
            pair<int,int> nextPos = {curPos.first + dir[i].first,curPos.second + dir[i].second};
            if(!((0 <= nextPos.first && nextPos.first < 4) && ((0 <= nextPos.second && nextPos.second < 4)))) continue; // backtracking
            int heu = heuristic(curPos,nextPos,b);
            candPos.push({heu,nextPos});
        }
        while(!candPos.empty()){
            pair<int,int> p = candPos.top().second;
            swap(b[curPos.first][curPos.second],b[p.first][p.second]);
            if(!check_generated(b)){
                candPos.pop();
                continue;
            }
            puzz(step + 1,b,p);
            swap(b[curPos.first][curPos.second],b[p.first][p.second]);
            candPos.pop();
        }
        
        
    }
}   

int main(){
    vector<vector<int>> b(4,vector<int>(4));
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            cin >> b[i][j];
            if(b[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    puzz(0,b,{x,y});
    cout << res << "\n";
    return 0;
}