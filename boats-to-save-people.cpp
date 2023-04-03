class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       sort(people.begin(),people.end()); // sort the array in ascending order.
      
       int low=0; // initialize first pointer
       int high=people.size()-1; // initialize last pointer
       int ans=0; // counter variable for minimum required boat
        while(low<=high){
            if(people[low] + people[high]<=limit){ // if sum of 1st and last pointer weight is smaller than or equal to limit then we will increase 1st pointer & counter variable and decrease last pointer. 
                ans++;
                low++;
                high--;
            }
            else if(people[low]>=limit){ // if 1st pointer weight is greater than or equal to limit that means need 1 boat because the sum of the weight of those people is at most limit.
                ans++;
                low++;
            }
            else if(people[high]>=limit){ // if last pointer weight is greater than or equal to limit that means need 1 boat because the sum of the weight of those people is at most limit.
                ans++;
                high--;
            }
            else{ // this is the situation where sum of 1st and last pointer weight is greater than limit. so, we will decrease last pointer because will become sum of 1st and new last pointer weight is smaller than or equal to limit.
                high--;
                ans++;
            }
        }
        return ans;
    }
};