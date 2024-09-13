class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;

        int n = queries.size(),m=0;

         for(int i=0;i<n;i++)
          {
              int a= queries[i][0];
               int b = queries[i][1];
              for(int j=a;j<=b;j++)
               {
                  m^= arr[j];
               }
               ans.push_back(m);
                m=0;
          }

          return ans;

    }
};