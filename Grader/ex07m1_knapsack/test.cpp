#include <bits/stdc++.h>
using namespace std;

int main(){
    int x = 3;
    vector<int> v = {5,5,5,5};
    int y = accumulate(v.begin(),v.end(),x);
    cout << x << " " << y ;
    return 0;
}