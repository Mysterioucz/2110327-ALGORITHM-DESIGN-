#include <bits/stdc++.h>
using namespace std;

long long get_sum(const vector<long long> &s,int a,int b){ // if the vector not pass by ref it's can cause time out (because it need to copy into the function)
    return s[b] - s[a - 1];
}

long long mss(const vector<long long> &data,int start, int stop, const vector<long long> &s){
    if(start == stop){
        return data[start];
    }
    int m = (start + stop)/2;
    long long r1 = mss(data, start, m, s); // max sum of sub seq in the left
    long long r2 = mss(data, m + 1, stop, s);// max sum of sub in the right

    long long maxLeft = get_sum(s,m,m);
    for(int i = start;i < m;i++){
        maxLeft = max(maxLeft,get_sum(s,i,m));
    }
    long long maxRight = get_sum(s,m+1,m+1);
    for(int i = m + 2;i <= stop;i++){
        maxRight = max(maxRight,get_sum(s,m + 1,i));
    }

    long long r3 = maxLeft + maxRight;
    return max(r1,max(r2,r3));
}

int main(){
    int n;
    cin >> n;
    vector<long long> data(n+1);
    vector<long long> s(n+1);
    s[0] = 0;
    for(int i = 1;i < n + 1;i++){
        cin >> data[i];
        s[i] = s[i - 1] + data[i];
    }
    cout << mss(data,1,n,s) << "\n";
    return 0;
}