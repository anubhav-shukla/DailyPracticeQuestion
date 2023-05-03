class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer;
        unordered_map<int, int> map1, map2;
        for (auto i : nums1)
            map1[i]++;
        for (auto i : nums2)
            map2[i]++;
        vector<int> temp1;
        for (auto i : nums1){
            if (map1[i] > 0 && map2.count(i) == 0)
                temp1.push_back(i);
            map1[i] = 0;
        }
        vector<int> temp2;
        for (auto i : nums2){
            if (map2[i] > 0 && map1.count(i) == 0)
                temp2.push_back(i);
            map2[i] = 0;
        }
        answer.push_back(temp1);
        answer.push_back(temp2);
        return answer;
    }
};