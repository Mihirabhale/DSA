class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left  = 0;
        int right = (int)nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // target in left half
                } else {
                    left = mid + 1;   // target in right half
                }
            }
            // right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // target in right half
                } else {
                    right = mid - 1;  // target in left half
                }
            }
        }

        return -1;
    }
};