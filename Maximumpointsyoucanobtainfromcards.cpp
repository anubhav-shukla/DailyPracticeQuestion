#include <bits/stdc++.h>
using namespace std;

    int maxScore(vector<int>& cardPoints, int k) {
    
    int n = cardPoints.size();

    int i = 0;
    int j = 0;
    int len = n-k;
    int ans = INT_MAX;
    int temp = 0;
    
    // find minimum subarray sum of len==n-k
    while(j<n){
        
        while(j<n && j<i+len){
           temp+=cardPoints[j];
           j++; 
        }
        
        if(j-i==len){
           ans = min(temp,ans);
           temp = temp - cardPoints[i];
           i++; 
        }
        
    }
    
    int sum = 0;
    for(int i = 0;i<n;i++)sum+=cardPoints[i];

    
    return sum - ans;
    
}
int main()
{
    vector<int> vect;
    vect.push_back(2);
    vect.push_back(3); 
    vect.push_back(25);
    vect.push_back(24);
    vect.push_back(7);
    vect.push_back(2);
    vect.push_back(9);
    cout << maxScore(vect,3);
 
    return 0;
}
