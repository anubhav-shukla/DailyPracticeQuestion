
#include <bits/stdc++.h>
using namespace std;

int solution(int index, vector<int>& job,int d,vector<vector<int>>& dp)
{
    int n = job.size();
    if(d==1)
    {
        /*
        This conditon means that we have only 1 day left with us 
        So in this day i only need to find out the most expensive day which i have right now 
        */
        int mx = job[index];
        for(int i =index;i<n;i++)
        {
            mx = max(mx, job[i]);
            /*
            just trying to find the most high value of the job present 
            */
        }
        return mx;;
    }
    
    //Now considier that the index tha ti provided to you alread have an value 
    //in this case iu will just find the dp whcih is present and send it as a letter 
    if(dp[index][d]!=-1) return dp[index][d];
    
    //Now my actuall logic will start;
    /*
    In this logic i will just iterate from the index to the n 
    then i will find if i get anything max from the current result or not 
    when i get the mx i will just add it to the answert and then i will reduce the day trying to find of 
    if there is another optimal soluytion present or not at that time of the iteration 
    then i will find it with decreasing the number of days
   
   
   */
    
    int mx=INT_MIN;
    int ans = INT_MAX;
    for(int i =index;i<=n-d;i++)
    {
        mx = max(mx,job[i]);
        ans =min(ans,mx+solution(i+1,job,d-1,dp));
    }
    
    return dp[index][d]=ans;
}

int minDifficulty(vector<int>& jobDifficulty, int d) {
 // here my only aim is to try fit the ob in such a way taht i can perform 
    /*
    In such a way that atleast 1 job can be done onece a day 
    to achieve this i will be using the dp /memorization technique 
    where i iwll alwys compare which is the maxmmum result ont can get fromt eh recursion 
    */
    
    int n = jobDifficulty.size();
    if(n<d)return -1;
    //Corner case when the soution cant be find bcz the number of days are comparitevly high
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //Creating the dp so i dont need to find the soution of the oslution whcih is already seen by me 
    return solution(0,jobDifficulty,d,dp);
        
}

int main(){
    vector<int> jobDifficulty = {6,5,4,3,2,1};
    int d = 2;
    cout<<minDifficulty(jobDifficulty,d);
}