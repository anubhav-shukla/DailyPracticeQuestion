class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            long long sum = 0;
            int size = q.size();

            for (int i = 0;i < size;i ++) {
                TreeNode* front = q.front();
                q.pop();

                sum += front->val;

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

            if (pq.size() < k) {
                pq.push(sum);
            } else if (pq.top() < sum) {
                pq.pop();
                pq.push(sum);
            }
        }

        if (pq.size() < k) return -1;
        return pq.top();
    }
};