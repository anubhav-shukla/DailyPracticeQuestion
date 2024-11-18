class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n=code.size();
        int sum;
        
        for(int i=0;i<n;i++){
            sum=0;
           if(k>0){
            int j=i+1;
            for(int cnt=0;cnt<k;cnt++){
                sum+=code[(j)%n];
                j++;
            }
            ans.push_back(sum);
           }
           else if(k<0){
            int j=i-1;
            for( int cnt=0;cnt<abs(k);cnt++){
                    sum+=code[((j%n)+n)%n];
                    j--;
            }
            ans.push_back(sum);
           }else{
                ans.push_back(0);
           }
        }
        return ans;
    }
};

