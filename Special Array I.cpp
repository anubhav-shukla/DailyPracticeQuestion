class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i)
            if (!((nums[i] ^ nums[i-1]) & 1)) // XOR reveals parity match
                return false; // 🚫 Same parity → invalid
        return true; // ✅ All pairs have opposite parity
    }
};
