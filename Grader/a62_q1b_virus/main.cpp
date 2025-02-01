#include <bits/stdc++.h>
using namespace std;


bool recur(int k , const vector<string> &v, int start, int stop, bool &mutant){
    if(k == 1){
        if(v[start] + v[stop] == "01"){
            mutant = false;
            return true;
        }else if(v[start] + v[stop] == "10" && mutant){
            mutant = true;
            return true;
        }
        return false;
    }
    bool l_mutant = true;bool r_mutant = false|| mutant;
    bool l = recur(k-1,v,start,(start + stop)/2,l_mutant);bool r = recur(k-1,v,(start + stop + 1)/2,stop,r_mutant);
    if(l && r){
        if(!l_mutant && r_mutant){ // if first half is not mutant then second cant be mutant
            return false;
        }
        return true;
    }
    return false;
}

bool recur2(int k , const vector<string> &v, int start, int stop, bool mutant){
    if(k == 1){
        if (mutant) {
            return v[start]+v[stop] == "10";
        }
        return v[start]+v[stop] == "01";
    }
    if (mutant) {
        return recur2(k-1, v, start, (start+stop)/2, true) && (recur2(k-1,v,(start + stop + 1)/2,stop, false) || recur2(k-1,v,(start + stop + 1)/2,stop, true));
    }
    return (recur2(k-1,v,start,(start + stop)/2, true) || recur2(k-1, v, start, (start+stop)/2, false)) && recur2(k-1,v,(start + stop + 1)/2,stop, false);
}

int main(){
    int n,k,size = 1;
    cin >> n >> k;
    for(int i = 0;i < k;i++) size *= 2;
    while(n--){
        vector<string> data(size);
        for(int i = 0;i < pow(2.0,k);i++){
            cin >> data[i];
        }
        bool in = false;
        if(recur2(k,data,0,data.size() - 1,in)) cout << "yes" << "\n";
        else cout << "no" << "\n";
        
    }
    return 0;
}