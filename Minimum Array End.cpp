class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        if (n == 1)
            return ans;
        --n;
        vector<int> ref;
        for (long long i = 0; i < 64; i++) {
            if (!(ans & (1ll << i)))
                ref.push_back(i);
        }
        for (int i = 0; n; i++, n >>= 1) {
            ans += (n & 1ll) << ref[i];
        }

        return ans;
    }
};