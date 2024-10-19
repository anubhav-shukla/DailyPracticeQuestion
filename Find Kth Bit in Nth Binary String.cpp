class Solution {
public:
    char findKthBit(int n, int k) {
        // S1 => 1           => 2^1 - 1
        // S2 => 1 + 2*1     => 2^2 - 1
        // S3 => 1 + 2*3     => 2^3 - 1
        // Sn => 1 + 2*S_n-1 => 2^n - 1
        if(n == 1) return '0';
        int numOfBit = pow(2, n) - 1;
        if(k == numOfBit / 2 + 1) {
            return '1';
        } else if(k < numOfBit / 2 + 1) {
            char c = findKthBit(n - 1, k);
            return c;
        } else {
            int rightShift = k - (numOfBit / 2 + 1);
            int newK = numOfBit / 2 + 1 - rightShift;
            char c = findKthBit(n - 1, newK);
            return c == '0'? '1': '0';
        }
    }

};