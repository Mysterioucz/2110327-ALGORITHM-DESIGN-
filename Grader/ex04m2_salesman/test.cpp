#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> p,seq;
vector<int> psa;
int a,b,totalCost = 0;

int distance(int start, int end, int a, int b, const vector<int>& p, int totalCost) {
    int m = p.size();
    int distCW = 0;
    int distCCW = 0;

    // Calculate clockwise distance
    for (int i = start; i != end; i = (i + 1) % m) {
        distCW += p[i];
    }

    // Calculate counter-clockwise distance
    for (int i = start; i != end; i = (i - 1 + m) % m) {
        distCCW += p[(i+m-1) % m]; 
    }


    // Check portal usage (from a to b)
    int distWithPortalAB = 0;
    if (a != b) { 
        
        int distStartToA = 0;
        for (int i = start; i != a; i = (i + 1) % m) {
            distStartToA += p[i];
        }

        int distBToEnd = 0;
        for (int i = b; i != end; i = (i + 1) % m) {
            distBToEnd += p[i];
        }

        distWithPortalAB = distStartToA + distBToEnd;
        
        // if(end < start || (end > start && !(start <= a && a < end))){
        //     for (int i = start; i != end; i = (i - 1 + m) % m) {
        //         distCCW += p[(i+m-1) % m]; 
        //     }
        // }

        
    }

    // Check portal usage (from b to a) - similar logic as above

    return min({distCW, distCCW, distWithPortalAB});
}

int main() {
    // ... (your input code remains the same)
    int n,m;
    cin >> n >> m;
    seq.resize(m);
    p.resize(m);
    psa.resize(m);
    for(int &e:seq) cin >> e;
    for(int &e:p){
        cin >> e;
        totalCost += e;
    }
    psa[0] = 0;
    for(int i = 1;i < m;i++){
        psa[i] = psa[i-1] + p[i-1];
    }
    for (int _ = 0; _ < n; ++_) {
        int a, b;
        cin >> a >> b;

        int cost = 0;
        for (int i = 0; i < m; ++i) {
            cost += distance(seq[i], seq[(i + 1) % m], a, b, p, totalCost);
        }
        cout << cost << endl;
    }

    return 0;
}