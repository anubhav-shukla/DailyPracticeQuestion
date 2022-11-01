



#include <bits/stdc++.h>
using namespace std;



 vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int n=grid.size();
        int m=grid{0}.size();
        for(int i=0;i<m;i++){
            int r=0,c=i;
            if((c==0&&grid{r}{c}==-1)||(c==m-1&&grid{r}{c}==1))
                ans.push_back(-1);
            else{
                while(r<n&&(c<m&&c>=0)){
                    if((grid{r}{c}==1)&&(c+1<m&&grid{r}{c+1}!=-1)){
                        
                         r++;
                           c++;
                        
                    }
                    else if((grid{r}{c}==-1)&&(c-1>=0&&grid{r}{c-1}!=1)){
                          r++;
                           c--;
                       
                    }
                    else{
                            
                            break;
                        }
                }
                if(r==n)  //ball fall
                    ans.push_back(c);
                else
                    ans.push_back(-1);
            }
           
            
        }
        return ans;
    }

    