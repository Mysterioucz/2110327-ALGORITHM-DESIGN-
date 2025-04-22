#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g; // adjacency matrix
vector<int> s;
int n,m,k,res = INT_MAX/2;


void floyd_warshall(){
    // we will use g as distance
    for(int x = 0;x < n;x++){
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                g[i][j] = min(g[i][j],g[i][x] + g[x][j]);
            }
        }
    }
}
struct comp{
    int startPos;
    comp(int pos) : startPos(pos) {}
    bool operator()(const int &a,const int &b) const {
        return g[startPos][a] > g[startPos][b]; // Example comparison logic
    }
};
void stateS(map<int,bool> &visited,int curPos,int totalVisit,int totalCost){
    if(totalVisit < k){
        if(totalCost > res) return;
        priority_queue<int,vector<int>,comp> pq(curPos); // minHeap
        for(int i = 0;i < k;i++){
            if(s[i] != curPos && !visited[s[i]]){
                pq.push(s[i]);
            }
        }
        while(!pq.empty()){
            int nextPos = pq.top();
            if(!visited[nextPos]){
                visited[nextPos] = true;
                stateS(visited,nextPos,totalVisit + 1,totalCost + g[curPos][nextPos]);
                visited[nextPos] = false;
            }else{
                stateS(visited,nextPos,totalVisit,totalCost + g[curPos][nextPos]);
            }
            pq.pop();
        }
    }else{
        res = min(res,totalCost);
    }
    
}

int main(){
    cin >> n >> m >> k;
    s.resize(k);
    g.resize(n,vector<int>(n,INT_MAX/9));
    for(int i = 0;i < n;i++) g[i][i] = 0;
    for(int i = 0;i < k;i++){
        cin >> s[i];
        s[i]--;
    }
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a-1][b-1] = c;
        g[b-1][a-1] = c;
    }

    floyd_warshall();
    for(int i  = 0;i < k;i++){
        map<int,bool> visited;
        visited[s[i]] = true;
        stateS(visited,s[i],1,0);
    }
    
    cout << res;
    return 0;
}