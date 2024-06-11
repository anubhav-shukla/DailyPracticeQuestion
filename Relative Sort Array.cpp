class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        // Frequency array to count occurrences of each element in arr1 (range 0-1000)
        int frequency[1001] = {0};
        int arr1Length = arr1.size();
        int resultIndex = 0;
        int maxElement = 0;
        // Count the frequencies of each element in arr1 and track the maximum element
        for (int num : arr1)
        {
            frequency[num]++;
            maxElement = max(num, maxElement);
        }
        // Result vector to store the sorted elements
        vector<int> sortedArray(arr1Length);
        // Add elements of arr2 to result in the order they appear in arr2
        for (int num : arr2)
        {
            while (frequency[num]-- > 0)
            {
                sortedArray[resultIndex++] = num;
            }
        }
        // Add remaining elements not in arr2 to result in ascending order
        for (int num = 0; num <= maxElement; num++)
        {
            while (frequency[num]-- > 0)
            {
                sortedArray[resultIndex++] = num;
            }
        }
        return sortedArray;
    }
};