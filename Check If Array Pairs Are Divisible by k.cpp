class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>positive(k,0);
        vector<int>negative(k,0);

        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                int a=-arr[i];
                a=a%k;
                negative[a]++;
            }
            else{
                int a=arr[i]%k;
                positive[a]++;
            }
        }

        int i=1;
        int j=k-1;

        if((positive[0]+negative[0])%2 ==1){
            return false;
        }

        while(i<=j){
            if(i==j){
                int cnt=negative[i]+positive[i];
                if(cnt%2 ==1){
                  return false;
                }
            }
            int cnt1=positive[i]+negative[j];
            int cnt2=negative[i]+positive[j];
            if(cnt1 != cnt2){
                  return false;
            }
            i++;
            j--;
        }

        return true;
    }
};