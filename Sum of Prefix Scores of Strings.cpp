class Solution {
    public:
    vector<int> sumPrefixScores(vector<string>& words) {
        auto A = words.begin(), Z = words.end();
        vector<int> I(Z-A, 0); iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [=](int i, int j){ return A[i] < A[j]; });
        sort(A, Z);
        vector<int> ans(Z-A, 0);
        for(int k = 0; string_view w: words) {
            int n = w.size(), sum = 0;
            auto a = A, z = Z-1;
            for(int i = 0; i < n; ++i) { /* here we maintain the invariant, for all x in [a,z), x[..i) == w[..i) */
                while(a->size() == i || a[ 0][i] < w[i]) ++a;
                while(z[0][i] > w[i]) --z;
                sum += z +1- a;
            }
            ans[I[k++]] = sum;
        }
        return ans;
    }
};