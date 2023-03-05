class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++) 
            mp[arr[i]].push_back(i);

        // <index, type>
        queue<pair<int, bool>> q;
        q.push({0, true});
        q.push({0, false});
        vector<int> jump(n, INT_MAX);
        jump[0]=0;

        //process the queue to reach the last element
        int lastIdx = n - 1;
        while (!q.empty()) {
            //cout<<q.front().first<<","<<q.front().second<<endl;
            int currIdx = q.front().first;
            int jumpCount = jump[currIdx] + 1;
            if (currIdx == lastIdx)
                return jump[lastIdx];
            //process elements of same value
            if (q.front().second) {
                for (auto pos : mp[arr[currIdx]])
                    if (jump[pos] > jumpCount) {
                        jump[pos] = jumpCount;
                        q.push({pos, false});
                    }
                mp[arr[currIdx]] = vector<int>();
            }
            //process front and back nodes
            else {
                if (currIdx < lastIdx)
                    if (jump[currIdx + 1] > jumpCount) {
                        jump[currIdx + 1] = jumpCount;
                        q.push({currIdx + 1, true});
                        q.push({currIdx + 1, false});
                    }
                if (currIdx > 0)
                    if (jump[currIdx - 1] > jumpCount) {
                        jump[currIdx - 1] = jumpCount;
                        q.push({currIdx - 1, true});
                        q.push({currIdx - 1, false});
                    }
            }
            q.pop();
        } 
        return -1;
    }
};