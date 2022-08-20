  #include <bits/stdc++.h>
using namespace std; 


int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    
        int ans=0,i=0;
        int curr=startFuel;
        // corner case
       if(target<curr) return 0;
       // if(curr<stations[0][0]) return -1;
        // max heap
        priority_queue<int>pq;
        while(curr<target){
            while(i<stations.size() && stations[i][0]<=curr){
                pq.push(stations[i++][1]);
            }
            if(pq.empty()) return -1;
            curr+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }



    int  main(){
        int target = 100, startFuel = 1;
         vector<vector<int>> stations = {{10,100}};
        cout<<minRefuelStops(target,startFuel,stations);
    }