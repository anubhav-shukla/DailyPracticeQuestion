class Solution {
public:
    int count = 0;
    int res;

    void fun(vector<int>& v, int start, int temp) {
        if (temp > res) return;
        if (temp == res) count++;

        for (int i = start; i < v.size(); i++) {
            fun(v, i + 1, temp | v[i]);
        }
    }

    int countMaxOrSubsets(vector<int>& n) {
        int temp = 0;
        for (int i = 0; i < n.size(); i++) {
            temp |= n[i];
        }
        res = temp;
        fun(n, 0, 0);
        return count;
    }
};