class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        int count=0;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i][0]==46 && logs[i][1]==46 && logs[i][2]==47)
                { count--;
                  if(count<0) count=0;}
            else if(logs[i][0]==46 && logs[i][1]==47) ;
            else
                count++;
        } 
        if(count<0)
            count=0;
        return count;
    }
};