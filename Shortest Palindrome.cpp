class Solution {
public:
    vector<int> zfunc(string s)
    {
      int n=s.size();
      vector<int> z(n,0);
      
      int l=0,r=0;
      for(int i=1;i<n;i++)
      {
        if(i<r)
          z[i]=min(z[i-l],r-i);

        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
          z[i]++;

        if(i+z[i]>r)
          l=i,r=i+z[i];     
      }
      return z;
    }

    string shortestPalindrome(string s) {
      int n=s.size();
      string rev_s=s;
      reverse(rev_s.begin(),rev_s.end());
      string temp=s+"$"+rev_s;

      vector<int> z=zfunc(temp);
      int val=0,total=z.size();
      for(int i=n+1;i<total;i++)
      {
        if(z[i]>=total-i)
          val=max(val,z[i]);
      }

      string s3=s.substr(val,n-val);
      reverse(s3.begin(),s3.end());
      return s3+s;  
    }
};