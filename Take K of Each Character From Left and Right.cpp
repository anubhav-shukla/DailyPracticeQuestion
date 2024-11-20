class Solution {
public:
    int takeCharacters(string s, int k) {
        
        map<int,int>mp;
        int n=s.size();
        int l=0;
        int r=0;

        for(int i=0;i<n;i++)mp[s[i]-'a']++;

        for(int i=0;i<3;i++)if(mp[i]<k)return -1;

        int ans=0;

    // map<int,int>mpp;

        while(l<n)
        {
         mp[s[l]-'a']--;
         while(r<=l&&(mp[0]<k || mp[1]<k || mp[2]<k ))
         {
            mp[s[r]-'a']++;
            r++;
           
         }
          ans=max(ans,l-r+1);
          cout<<l<<r<<endl;
         l++;

        }

        return n-ans;
    }
};