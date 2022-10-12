#include<bits/stdc++.h>
using namespace std;

int largestPerimeter(vector<int>& nums){
    int n=nums.size();
    int a =0,b=0,c=0;
    int peri=0;
    sort(nums.begin(),nums.end());
    for(int i=n-1;i>=2;--i){
        a=nums[i],b=nums[i-1],c=nums[i-2];
        if(a+b>c && b+c>a && c+a>b){
            peri=a+b+c;
            break;
        }
    }
    return peri;
}

int main(){
    vector<int> num={1,2,1};
    cout<<largestPerimeter(num);
}