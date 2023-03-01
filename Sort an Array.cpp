class Solution {
public:
int partition(vector<int>& nums, int si, int ei) {
    int pivot = nums[si + rand() % (ei - si + 1)];
    int i = si - 1, j = ei + 1;
    while (true) {
        do {
            i++;
        } while (nums[i] < pivot);
        do {
            j--;
        } while (nums[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(nums[i], nums[j]);
    }
}

void quicksort(vector<int>& nums, int si = 0, int ei = -1) {
    if (ei == -1) {
        ei = nums.size() - 1;
    }
    if (si >= ei) {
        return;
    }
    int p = partition(nums, si, ei);
    quicksort(nums, si, p);
    quicksort(nums, p + 1, ei);
}

vector<int> sortArray(vector<int>& nums) {
    quicksort(nums);
    return nums;
}

};