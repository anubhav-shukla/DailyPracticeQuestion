class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> array;
        for (auto& num : arr)
            array.insert(num);
        unordered_map<int, int> mp;
        int i = 1;
        for (auto itr = array.begin(); itr != array.end(); itr++) {
            mp[*itr] = i++;
        }
        for (auto& num : arr)
            num = mp[num];
        return arr;
    }
};