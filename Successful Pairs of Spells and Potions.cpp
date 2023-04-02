class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long k) {
        int n=s.size();
        vector<int>v;
        sort(p.begin(),p.end());
        int m=p.size();
        for(int i=0;i<n;i++)
        {
            long long x=ceil(k/(s[i]*1.0));
            int y=lower_bound(p.begin(),p.end(),x)-p.begin();
            //cout<<y<<endl;
            v.push_back(m-y);
        }
        return v;
    }
};