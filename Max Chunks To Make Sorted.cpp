class Solution 
{
public:
    
    int maxChunksToSorted(vector<int>& arr) 
    {
        int maxVal = 0;
        int count = 0;
        
        for (size_t i = 0; i < arr.size(); ++i)
        {
            maxVal = max(maxVal, arr[i]);
            if (maxVal <= i)
            {
                maxVal = 0;
                ++count;
            }
        }
        
        return count;
    }
};