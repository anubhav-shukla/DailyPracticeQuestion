class Solution {
public:
    bool canSortArray(vector<int>& a) {
        vector<int> b;
        b = a;
        sort(b.begin(), b.end());
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] <= a[i])continue;

            string s = bitset<32>(a[i]).to_string();
            string t = bitset<32>(a[i - 1]).to_string();

            sort(s.begin(), s.end());
            sort(t.begin(), t.end());

            if (s != t)return 0;
            swap(a[i], a[i - 1]);
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i])continue;

            string s = bitset<32>(a[i]).to_string();
            string t = bitset<32>(b[i]).to_string();

            sort(s.begin(), s.end());
            sort(t.begin(), t.end());

            if (s != t)return 0;
        }

        return 1;
    }
};