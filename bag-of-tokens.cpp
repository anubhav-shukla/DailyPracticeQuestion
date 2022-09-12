int bagOfTokensScore(vector<int>& tokens, int power) {
       sort(tokens.begin(),tokens.end());
        int s=0;//we will put score in s
        if(tokens.empty()) return 0;
        if(power<tokens[0]) return s;
        else{ power-=tokens[0];
             s++;}
        int n=tokens.size();
        int start=1,end=n-1,sum=0;
        for(int i=1;i<tokens.size();i++){
            sum+=tokens[i];
        }
        while(1){
            if(start==end){
                if(power<tokens[start]) return s;
                else {s++;
                return s;}
            }
            else if(power>=sum) return s+end-start+1;
            else if(power< tokens[start]){
                power+=tokens[end];
                sum-=tokens[end];
                end--;
                s--;
            }
            else if((power>=tokens[start]) && start<end){
                power-=tokens[start];
                sum-=tokens[start];
                start++;
                s++;
            }
            
        }
        return 0;
    }