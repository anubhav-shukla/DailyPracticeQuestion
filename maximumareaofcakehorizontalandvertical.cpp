#include <bits/stdc++.h>
using namespace std;

    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int maxh = max(hc[0], h - hc.back()),
            maxv = max(vc[0], w - vc.back());
        for (int i = 1; i < hc.size(); i++)
            maxh = max(maxh, hc[i] - hc[i-1]);
        for (int i = 1; i < vc.size(); i++)
            maxv = max(maxv, vc[i] - vc[i-1]);
        return (int)((long)maxh * maxv % 1000000007);
    }

int main(){
    vector<int> horizontalCuts ;
    horizontalCuts.push_back(1);
    horizontalCuts.push_back(2); 
    horizontalCuts.push_back(4);
    
    vector<int> verticalCuts ;
    verticalCuts .push_back(1);
    verticalCuts .push_back(3);
    cout << maxArea(5,4,horizontalCuts,verticalCuts);

}