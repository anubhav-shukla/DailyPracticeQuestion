class Solution {
public:
   string backtrack(int &i, string &s, string &temp){
        for(;i<s.size();i++){
             if (s[i]=='('){
                  i++;
                  string x = "";
                  temp += backtrack(i, s, x);
             }else if (s[i]==')'){
                 reverse(temp.begin(), temp.end());
                return temp;
             }else{
                temp += s[i];
             }
        }
        return temp;
   }
    string reverseParentheses(string s) {
         int i =0;
         string x="";
         return  backtrack(i,s,x);
    }
};