class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = -1e9;
        unordered_map<int,int>hash;
        int i = 0;
        int j = 0;
        int n = fruits.size();
        while(j<n){
            if(hash.size()<=2){
                hash[fruits[j]]++;
                j++;
            }
             if(hash.size()==2){
                int temp = 0;
                for(const auto el : hash){
                    temp+=el.second;
                }
                ans=max(ans,temp);
            }
            else if(hash.size() >2){
                while(hash.size()>2){
                    hash[fruits[i]]--;
                    if(hash[fruits[i]] == 0)
                        hash.erase(fruits[i]);
                    i++;
                }
            }
        }
        if(hash.size()<2){
            int temp=0;
           for(const auto el : hash){
                    temp+=el.second;
            }
                ans=max(ans,temp); 
        }
        return ans;
    }
};