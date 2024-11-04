class Solution {
public:
    string compressedString(string word) {
        string comp="";
        if(word.length()==0){
            return "";
        }
        int count=0;
        for(int i=0;i<word.length();){
            count=1;
            int j =i;
            while(j+1<word.length() && word[j]==word[j+1] && count<9){
                count++;
                j++;

            }
            comp += to_string(count)+word[i];
            i=j+1;

        }
        return comp;
        
    }
};