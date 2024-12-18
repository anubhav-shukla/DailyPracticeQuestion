 class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i=0,n=prices.size();
        stack<int> st;
        while(i<n){
            if(st.empty()){
                st.push(i);
            }else{
                while(!st.empty() && prices[st.top()]>=prices[i] && st.top()!=i){
                    prices[st.top()]-=prices[i];
                    st.pop();
                }
                st.push(i);
            }
            i++;
        }
        return prices;
    }
};