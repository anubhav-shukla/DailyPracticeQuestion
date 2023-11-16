class Solution {
public:

    string findDifferentBinaryString(vector<string>& nums) {
        const int size = nums.size(); // Number of binary strings in the input vector

        // Sort the input vector in lexicographical order
        sort(nums.begin(), nums.end());

        int pointer = 0; // Pointer to track the expected decimal value for the next binary string

        // Iterate through the sorted binary strings
        for(int i = 0; i < size; ++i) {
            // Convert the current binary string to decimal
            unsigned long decimalValue = bitset<16>(nums[i]).to_ulong();

            // Check if the decimal value matches the expected value
            if(decimalValue == pointer)
                pointer++;
            else
                // If not, return the binary representation of the expected value with appropriate length
                return bitset<16>(pointer).to_string().substr(16 - size);
        }

        // If no unique binary string is found, return the binary representation of the next expected value
        return bitset<16>(pointer).to_string().substr(16 - size);
    }
};