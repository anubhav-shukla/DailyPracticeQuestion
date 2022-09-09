   #include <iostream>
using namespace std;
   
   static bool comp(vector<int> &e1,vector<int> &e2){
        if(e1[0]==e2[0]){
            return e1[1]<e2[1];
        }
        return e1[0]>e2[0];
            
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        int ans = 0;
        int defenseMax = 0;
        for(auto it:properties){
            if(it[1]<defenseMax)
                ans++;
            else
                defenseMax = it[1];
        }
        return ans;
    }