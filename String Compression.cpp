class Solution {
public:
    int compress(vector<char>& chars) {
        string a="\0";
        int c=0;
        if(chars.size()==1)
        return 1;
        int n=chars.size()-1;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]==chars[i-1])
            c++;
            else{
                a=a+chars[i-1];
                if(c>=1)
            a=a+to_string(c+1);
            c=0;
            }
        }
         if(chars[n]==chars[n-1])
         {
            a=a+chars[n];
            a=a+to_string(c+1);
         }
         else
         {
             a=a+chars[n];
         }
        for(int i=0;i<a.size();i++)
        chars[i]=a[i];
       return a.size();
    }
};