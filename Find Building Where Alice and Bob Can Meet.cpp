class Solution {
public:
    
    vector<int> tree ;

    void buildSegmentTree(int nodeIndex, int nodeRangeLeft, int nodeRangeRight, vector<int>&A){
       if(nodeRangeLeft == nodeRangeRight){
           // leaf node
           tree[nodeIndex] = A[nodeRangeLeft];
           return ;
       }

       int mid = nodeRangeLeft + (nodeRangeRight-nodeRangeLeft)/2;

       buildSegmentTree(2*nodeIndex, nodeRangeLeft, mid, A);
       buildSegmentTree(2*nodeIndex+1, mid+1, nodeRangeRight, A);

       // backtracking, once children are filled, we will update the current node
       tree[nodeIndex] = max(tree[2*nodeIndex], tree[2*nodeIndex+1]);
    }


    int querySegmentTree(int nodeIndex, int nodeRangeLeft, int nodeRangeRight, int queryRangeLeft, int queryRangeRight, int x){
       if( (queryRangeLeft > nodeRangeRight) || (queryRangeRight < nodeRangeLeft) ){ // no overlap at all
           return -1;
       } 

       if(tree[nodeIndex] <= x)
           return -1;

       if(nodeRangeLeft == nodeRangeRight)
           return nodeRangeLeft;
        
       int mid = nodeRangeLeft + (nodeRangeRight-nodeRangeLeft)/2;

       int leftNodeAns = querySegmentTree(2*nodeIndex, nodeRangeLeft, mid, queryRangeLeft, queryRangeRight, x);

        if(leftNodeAns!=-1)
            return leftNodeAns;

       int rightNodeAns = querySegmentTree(2*nodeIndex + 1, mid+1, nodeRangeRight, queryRangeLeft, queryRangeRight, x);

       return rightNodeAns;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        
        tree.resize(4*heights.size());
        buildSegmentTree(1, 0, heights.size()-1, heights);

        vector<int> Ans;
        
        for(auto x:queries){
            int l = x[0], r = x[1];
            if(l > r) swap(l,r);
            
            if(l == r){
                Ans.push_back(r);
                continue;
            }
            
            if(heights[l] < heights[r]){
                Ans.push_back(r);
            }
            else{
                Ans.push_back(querySegmentTree(1, 0, heights.size()-1, r+1, heights.size()-1, heights[l]));
            }
        }
        
        return Ans;
    }
};