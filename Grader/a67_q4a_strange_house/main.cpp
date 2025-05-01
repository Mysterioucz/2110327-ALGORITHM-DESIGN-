#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> visited,sol;
vector<int> bed;
map<string,bool> checkGen;
bool found = false;

int heuristic(){
    int c = 0;
    for(int i  = 0;i < 2*n;i++){
        if(i < n){
            if(bed[i] != 2) c++;
        }else{
            if(bed[i] != 1) c++;
        }
    }
    return c;
}

string bed_tostr(){
    string s = "";
    for(int e:bed){
        s += to_string(e);
    }
    return s;
}

bool check_bed(){
    for(int i  = 0;i < 2*n;i++){
        if(i < n){
            if(bed[i] != 2) return false;
        }else{
            if(bed[i] != 1) return false;
        }
    }
    return true;
}

void stateS(int curPos){
    if(!check_bed() && !found){
        string strBed = bed_tostr();
        if(checkGen.find(strBed) == checkGen.end()){
            checkGen[strBed] = true;
            for(int b:g[curPos]){
                swap(bed[curPos],bed[b]);
                sol.push_back(b);
                stateS(b);
                if(found) return;
                sol.pop_back();
                swap(bed[curPos],bed[b]);
            }
        }
    }else{
        found = true;

    }
}

int main(){
    cin >> n >> m;
    g.resize(2*n+1); // adjacency list collect node-1
    visited.resize(2*n+1);
    bed.resize(2*n+1,0);
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    for(int i = 0;i < 2 * n;i++){
        if(i < n) bed[i] = 1;
        else bed[i] = 2;
    }
    stateS(2*n);
    if(found){
        cout << sol.size() << "\n";
        for(int e:sol){
            cout << e+1 << " ";
        }
    }else cout << -1;
    

    return 0;
}