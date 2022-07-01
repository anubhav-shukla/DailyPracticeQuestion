#include <bits/stdc++.h>
using namespace std;
 static bool check(const vector<int> &v1,const vector<int> &v2){
    return v1[1]>v2[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(),boxTypes.end(),check);
    int count = 0;
   
    for(int i=0;i<boxTypes.size();i++){
        
        if(boxTypes[i][0]>=truckSize){
            count+= truckSize*boxTypes[i][1];
             truckSize = 0;
        }
        else{
          truckSize -= boxTypes[i][0];
            count += boxTypes[i][0]*boxTypes[i][1];
        }
		
    }
    
    return count;
}

int main(){
  vector<vector<int> > A{ { 2 }, { 3, 9 }, { 1, 6, 7 } }; 
    int truckSize = 4;
    cout<<maximumUnits(A,truckSize);
}