#include <bits/stdc++.h>
using namespace std;

int minStu = -1;
int n,m;

void day_cover(const vector<pair<int,vector<int>>> &stu, vector<bool> &used, set<int> s,int numberOfStu){
    if(s.size() < n){
        int maxCover = -1;
        vector<int> bestIdx;

        // find best choice from available student
        for(int i = 0;i < stu.size();i++){
            if(used[i] || stu[i].first < maxCover) continue;
            int count = stu[i].first;
            for(auto num:stu[i].second) {
                if(s.find(num) != s.end()) count--;
            }
            if(count > maxCover){
                maxCover = count;
                bestIdx = {i};
            }else if(count == maxCover){
                bestIdx.push_back(i);
            }
        }
        for(const auto &idx:bestIdx){
            used[idx] = true;
            set<int> tmp = s;
            for(auto num:stu[idx].second){
                tmp.insert(num);
            }
            day_cover(stu,used,tmp,numberOfStu + 1);
            used[idx] = false;
        }

    }else{
        if(minStu == -1){
            minStu = numberOfStu;
        }else{
            minStu = minStu < numberOfStu ? minStu:numberOfStu;
        }
    }
}

int main(){
    //solve using greedy algorithm not worked
    cin >> n >> m;
    vector<pair<int,vector<int>>> stu;
    vector<bool> used;
    set<int> s;
    int tmp;
    for(int i = 0;i < m;i++){
        cin >> tmp;
        if(tmp > 0){
            vector<int> v(tmp);
            for(auto &e:v){
                cin >> e;
            }
            stu.push_back(make_pair(tmp,v));
        }
    }
    used.resize(stu.size());
    sort(stu.begin(),stu.end(),greater<>());
    day_cover(stu,used,s,0);
    cout << minStu << "\n";

    return 0;
}