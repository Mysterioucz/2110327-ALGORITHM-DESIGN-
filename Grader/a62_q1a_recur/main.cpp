#include <bits/stdc++.h>
using namespace std;

void recur_matrix(vector<vector<int>> &v,int a, int b,int top,int bottom,int left,int right){
    if(a == 0){ // terminate case
        v[top][left] = b;
        return;
    }
    recur_matrix(v,a-1,b,top,(top + bottom + 1)/2,left,(left + right + 1)/2); // fill the top left of matrix H(a,b)
    recur_matrix(v,a-1,b - 1,top,(top + bottom + 1)/2,(left + right + 1)/2,right); // fill the top right of matrix H(a,b)
    recur_matrix(v,a-1,b + 1,(top + bottom + 1)/2,bottom,left,(left + right + 1)/2); // fill the bottom left of matrix H(a,b)
    recur_matrix(v,a-1,b,(top + bottom + 1)/2,bottom,(left + right + 1)/2,right); // fill the bottom left of matrix H(a,b)
    
}

int main(){
    int a,b;
    cin >> a >> b;
    vector<vector<int>> data(1 << a,vector<int>(1 << a));
    recur_matrix(data,a,b,0,1 << a,0,1<< a);
    for(const vector<int> &r:data){
        for(const int &e:r){
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}