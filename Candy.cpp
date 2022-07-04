#include <bits/stdc++.h>
using namespace std;
int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n, i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley); //Keep only the higher peak
        }
        return candy;
    }

    int main(){
        vector<int> horizontalCuts ;
    horizontalCuts.push_back(1);
    horizontalCuts.push_back(2); 
    horizontalCuts.push_back(4);
    
    horizontalCuts .push_back(1);
    horizontalCuts .push_back(3);
    cout<<candy(horizontalCuts);
    }