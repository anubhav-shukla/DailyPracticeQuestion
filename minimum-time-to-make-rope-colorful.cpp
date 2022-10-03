

 #include <bits/stdc++.h>
using namespace std;

 int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int i = n-1,mintime = 0;
		//stack maintains only those unique color with max neededTime in there same color group or subset
        stack<pair<char,int>> stk;
        stk.push({colors[i],neededTime[i--]});
        
        
        while(i >= 0){
            pair<char,int> p = stk.top();
            // cout << "top color = " << p.first << " " << " this color " << colors[i] << endl;
            if(p.first == colors[i]){
                // cout << "same " << i << endl;
                if(p.second > neededTime[i]){
                    mintime += neededTime[i--];
                    continue;
                }
                mintime += p.second;
                stk.pop();
                stk.push({colors[i],neededTime[i--]});
            }
            else{
                stk.push({colors[i],neededTime[i--]});
            }
        }
        
        return mintime;
    }
    int main(){
        string colors = "abaac";
        vector<int> neededTime = {1,2,3,4,5};
       cout<<minCost(colors,neededTime);
    }