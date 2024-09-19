class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i=0;i<expression.size();i++){
            char op=expression[i];
            if(op=='+' || op=='-' || op=='*'){
                vector<int> s1 = diffWaysToCompute(expression.substr(0,i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i+1));
                for(auto x:s1){
                    for(auto y:s2){
                        if(op=='+') ans.push_back(x+y);
                        else if(op=='-') ans.push_back(x-y);
                        else if(op=='*') ans.push_back(x*y);
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};