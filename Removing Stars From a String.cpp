class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto &x:s)
        {
            if(x=='*') 
                ans.pop_back();
            else
                ans+=x;
        }
        return ans;
        
    }
};