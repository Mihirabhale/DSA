class Solution {
public:
    int findMin(vector<int>& nums) {
        int left  = 0;
        int right = (int)nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;   // min is in right half
            } else {
                right = mid;      // min is in left half (mid could be min)
            }
        }

        return nums[left];  // left == right == min index
    }
};