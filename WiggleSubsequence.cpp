#include <bits/stdc++.h>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) {
            return 0;
        }
        vector<int> up(size, 0);
        vector<int> down(size, 0);
        
        up[0] = 1;
        down[0] = 1;
        for(int i=1; i<size; ++i){
            
            if (nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if (nums[i] < nums[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }
            else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[size-1], down[size-1]);
    }
    
int main(){
    vector<int> horizontalCuts ;
    horizontalCuts.push_back(1);
    horizontalCuts.push_back(2); 
    horizontalCuts.push_back(4);
    
    horizontalCuts .push_back(1);
    horizontalCuts .push_back(3);
    cout << wiggleMaxLength(horizontalCuts);

}