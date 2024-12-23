class Solution {
public:
    int getNumOfOperationsToSort(vector<int>& curLevel) {
        int res = 0, n = curLevel.size();
        vector<int> sorted = curLevel;
        sort(begin(sorted), end(sorted));
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[curLevel[i]] = i;
        for (int i = 0; i < n; i++) {
            if (curLevel[i] != sorted[i]) {
                int curPos = mp[sorted[i]];
                mp[curLevel[i]] = curPos;
                swap(curLevel[i], curLevel[curPos]);
                res++;
            }
        }
        return res;
    }

    int minimumOperations(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> curLevel(sz, 0);
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                curLevel[i] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res += getNumOfOperationsToSort(curLevel);
        }
        return res;
    }
};