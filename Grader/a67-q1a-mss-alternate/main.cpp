#include <bits/stdc++.h>
using namespace std;

int get_sum(const vector<int> &psaEven,const vector<int> &psaOdd, int a,int b){
    int sub1,sub2;
    if(a == b){
        sub2 = 0;
        if(a%2 == 0){
            sub1 = psaEven[b/2] - psaEven[b/2 - 1];
        }else{
            sub1 = psaOdd[(b + 1)/2] - psaOdd[(b + 1)/2 - 1];
        }
    }else if(a % 2 == 0){
        sub1 = psaEven[b/2] - psaEven[a/2 - 1];
        sub2 = psaOdd[(b + 1)/2] - psaOdd[(a+1)/2];
    }else{
        sub1 = psaOdd[(b + 1)/2] - psaOdd[(a + 1)/2 - 1];
        sub2 = psaEven[b/2] - psaEven[(a + 1)/2 - 1];
    }
    return sub1 - sub2;
}

int mcas(const vector<int> &v,int start,int stop, const vector<int> &psaEven,const vector<int> &psaOdd){
    if(start == stop) return v[start];
    int mid = (start + stop) / 2;
    int r1 = mcas(v,start,mid,psaEven,psaOdd);
    int r2 = mcas(v,mid + 1,stop,psaEven,psaOdd);

    int maxLeftEven = get_sum(psaEven,psaOdd,mid%2 == 0 ? mid:(mid-1),mid);
    int maxLeftOdd = get_sum(psaEven,psaOdd,mid%2 != 0 ? mid:(mid-1),mid);
    // int Idxstart = mid;
    // int minIdxstart = mid;
    for(int i = start;i < mid;i++){
        int tmp = get_sum(psaEven,psaOdd,i,mid);
        if(tmp > maxLeftEven && i%2==0){
            maxLeftEven = tmp;
            // maxIdxstart = i;
        }else if(tmp > maxLeftOdd && i % 2 != 0){
            maxLeftOdd = tmp;
            // minIdxstart = i;
        }
        // if(get_sum(psaEven,psaOdd,i,mid) > maxLeft){
        //     maxLeft = get_sum(psaEven,psaOdd,i,mid);
        //     // if(stop - start == v.size() - 1){ // for debugging
        //     //     cout << maxLeft << "\n";
        //     // }
        //     // maxIdxstart = i;
        // }
    }
    int maxRight = get_sum(psaEven,psaOdd,mid + 1,mid + 1);
    int minRight = get_sum(psaEven,psaOdd,mid + 1,mid + 1);
    for(int j = mid + 2;j <= stop;j++){
        int res = get_sum(psaEven,psaOdd,mid + 1,j);
        maxRight = max(maxRight,res);
        minRight = min(minRight,res);
        // if(stop - start == v.size() - 1){ // for debugging
        //     cout << maxRight << "\n";
        // }
    }
    int r3;
    if(mid%2 == 0){
        r3 = max(maxLeftEven - minRight,maxLeftOdd + maxRight);
    }else{
        r3 = max(maxLeftOdd - minRight,maxLeftEven + maxRight);
    }
    // if(stop - start == v.size() -  1) cout << "r1: " << r1 << " r2: " << r2 << " r3: " << r3 << "\n";
    return max(max(r1,r2),r3);

}

int main(){
    int n;
    cin >> n;
    vector<int> data(n + 1);
    vector<int> psa(n + 1);
    psa[0] = 0;
    vector<int> psaOdd((n)/2 + 1);
    vector<int> psaEven((n)/2 + 1);
    psaOdd[0] = 0;
    psaEven[0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> data[i];
        psa[i] = psa[i-1] + data[i];
        if(i % 2 == 0) psaEven[i/2] = psaEven[i/2 - 1] + data[i];
        else psaOdd[(i + 1)/2] = psaOdd[(i + 1)/2 - 1] + data[i];
    }
    int res = mcas(data,1,n,psaEven,psaOdd);
    cout << res << "\n";
    // int x = 10;
    // while(x--){
    //     cout << get_sum(psaEven,psaOdd,4,10) << "\n";
    // }
    
    return 0;
}