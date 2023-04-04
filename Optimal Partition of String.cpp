class Solution {
public:
    int partitionString(string s) {
        set<char> sa;
        int count=1;
        for(int i=0;i<s.size();i++){
            if(sa.find(s[i])!=sa.end()){
                sa.clear();
                sa.insert(s[i]);
                count++;
            }
            else{
                sa.insert(s[i]);
            }
        }
        return count;
    }
};