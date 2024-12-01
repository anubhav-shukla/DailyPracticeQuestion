class Solution {
public:
   bool checkIfExist(vector<int>& arr) {
        //hashmap to store elements
        map<float,int> m;
        for(int i = 0;i<arr.size();i++){
            //checking  for the doubled element

            float ele = float(arr[i])/2;
            // ceil or floor value of current element can be equal to 
            // any other element  in case of odd numbers to over come
            // the problem , we are using float datatype
            if((m.find((arr[i]*2)) != m.end()) || m.find(ele) != m.end()){
                return true;
            }
            m[(arr[i])] = i;
        }
        //after traversing the whole array, if we couldn't find the answer then returning false
        return false;
    }
};