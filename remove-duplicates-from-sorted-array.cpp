int removeDuplicates(vector<int>& nu) {
        int n=nu.size();
        int j=1;
        for(int i=1;i<n;i++){
             if(nu[i]!=nu[i-1]){
                 nu[j]=nu[i];
                 j++;
             }
        }
        return j;
    }