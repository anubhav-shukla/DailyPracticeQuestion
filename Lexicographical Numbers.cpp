class Solution {
public:
    void solve(int num, int n, vector<int> &res){
        if(num >n){
            return;
        }
        res.push_back(num);
        for(int append=0; append<=9; append++){
            int newn = (num*10)+append;
            if(newn > n){
                return;
            }
            solve(newn, n, res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int start=1; start<=9; start++){
            solve(start, n, res);
        }
        return res;
    }
};