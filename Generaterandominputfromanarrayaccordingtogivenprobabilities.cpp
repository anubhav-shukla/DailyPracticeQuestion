#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdlib>
#include<ctime>
using namespace std;

int random(vector<int> const &nums, vector<int> const &probability)
{
    int n=nums.size();
    if(n != probability.size()){
        return -1;
    }
    vector<int> prob_sum(n,0);
    prob_sum[0] = probability[0];

    for(int i=1;i<n;i++){
        prob_sum[i]=prob_sum.at(i-1)+probability[i];

    }
    int r = (rand() % 100) +1 ;

    if(r<= prob_sum[0]){
          return nums[0];
    }
    for(int i=1;i<n;i++){
        if(r>prob_sum.at(i-1) && r<= prob_sum[i]){
            return nums[i];
        }
    }
}
int main(){
    vector<int> nums = {1,2,3,4,5};
    vector<int> probability = {30,10,20,15,25};

    srand(time(NULL));

    unordered_map<int, int> freq;
 
    for(int i=0;i<1000000;i++){
        int val = random(nums, probability);
        freq[val]++;

    }
    for(int i=0;i<nums.size();i++){
        cout<< nums[i] << " ~ "<<freq[nums[i]]/10000.0 << "%" <<endl;
    }
    return 0;

}