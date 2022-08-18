  #include <bits/stdc++.h>
using namespace std; 
 
 int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int max = *max_element(arr.begin(), arr.end());
         vector<int> ans(max+1, 0);
        for(auto it : arr)
            ans[it]++;
        sort(ans.begin() , ans.end(), greater<int>());
        int reqsize = arr.size();
        int i =0;
        while(n/2<reqsize)
            reqsize -= ans[i++];
        return i;
    }


    int main(){
        vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
           cout<<minSetSize(arr);
    }