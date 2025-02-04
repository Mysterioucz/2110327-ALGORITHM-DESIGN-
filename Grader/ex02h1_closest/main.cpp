#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int, int> > vp;

int distance_between(const pair<int,int> &a,const pair<int,int> &b){
    int x = (a.first - b.first);
    int y = (a.second - b.second);
    return x*x + y*y;
}

bool compX(const pair<int,int> &a,const pair<int,int> &b){
    return a.first < b.first;
}
bool compY(const pair<int,int> &a,const pair<int,int> &b){
    return a.second < b.second;
}

int closest_pair(const vp &v_x,int start,int stop){
    // พิจารณาช่วง start ถึง stop
    if(stop - start <= 1){
        return distance_between(v_x[start],v_x[stop]);
    }

    int mid = (start + stop)/2; int mid_x = v_x[mid].first;
    int a = closest_pair(v_x, start, mid);
    int b = closest_pair(v_x, mid + 1, stop);
    int span = min(a,b);
    if (start == mid) span = b;
    else if(mid + 1 == stop) span = a;
    
    
    vp v_y;
    for(int i = start;i <= stop;i++){
        if(v_x[i].first < mid_x - span) continue;
        if(v_x[i].first > mid_x + span) break;
        v_y.push_back(v_x[i]);
    }
    sort(v_y.begin(),v_y.end());
    for(int i = 0;i < v_y.size();i++){
        for(int j = i + 1;j < v_y.size();j++){
            if(abs(v_y[i].second - v_y[j].second) > span) break;
            span = min(span,distance_between(v_y[i],v_y[j]));
        }
    }
    return span;

}

int main(){
    iostream::sync_with_stdio(false); cin.tie(NULL);
    int n,x,y;
    cin >> n;
    vp data_x(n); // data sorted by x value
    vp data_y(n); // data sorted by y value
    for(int i = 0;i < n;i++){
        cin >> x >> y;
        data_x[i] = make_pair(x,y);
        data_y[i] = data_x[i];
    }
    sort(data_x.begin(),data_x.end(),compX);

    cout << closest_pair(data_x,0,data_x.size() - 1) << "\n";    
    return 0;
}