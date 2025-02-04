#include <bits/stdc++.h>
using namespace std;

bool simString(string a, string b){
  if(a.size() == 1 && b.size() ==1){
    return a==b;
  }
  int mid = (a.size() + 1)/2;
  return (simString(a.substr(0,mid),b.substr(0,mid)) && simString(a.substr(mid,a.size() - mid),b.substr(mid,b.size() - mid)))|| (simString(a.substr(mid,a.size() - mid),b.substr(0,mid)) && simString(a.substr(0,mid),b.substr(mid,b.size() - mid)));
  
}

int main(){
  string s1,s2;
  cin >> s1 >> s2;
  if(simString(s1,s2)) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}