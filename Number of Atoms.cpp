class Solution {
public:
    map<string,int>m;
    bool isNumber(char c){
        return (c>='0' and c<='9');
    }
    pair<string,int> getElement(int ind,string &formula){
        int i=ind;
        string res="";
        for(;i>=0;){
            char c=formula[i--];
            if(c>='a' and c<='z'){
                res+=c;
            }
            else if(c>='A' and c<='Z'){
                res+=c;
                break;
            }
            else break;
        }
        reverse(res.begin(),res.end());
        return {res,i};
    }
    pair<int,int> getElementCount(int ind,string formula){
        int i=ind;
        string num="";
        for(;i>=0;i--){
            if(isNumber(formula[i])){
                num+=formula[i];
            }
            else break;
        }
        reverse(num.begin(),num.end());
        return {stoi(num),i};
    }

    string countOfAtoms(string formula) {
        stack<int>stk;
        stk.push(1);
        int c=1;
        string ele;
        int n=formula.size();
        for(int i=n-1;i>=0;){
            if(formula[i]==')'){
                stk.push(c*stk.top());
                c=1;
                i--;
            }
            else if(formula[i]=='('){
                stk.pop();
                i--;
            }
            else if(isNumber(formula[i]))
            {
                auto p=getElementCount(i,formula);  
                c=p.first;
                i=p.second;
            }
            else{
                auto p=getElement(i,formula);
                ele=p.first;
                i=p.second;
                m[ele]+=(c*stk.top());
                c=1;
            }
        }
        string res="";
        for(auto it:m){
            res+=it.first;
            if(it.second!=1)
                res+=to_string(it.second);
        }
        return res;
    }
};