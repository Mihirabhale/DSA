class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last  = findLast(nums, target);
        return {first, last};
    }

private:
    int findFirst(vector<int>& nums, int target) {
        int left  = 0;
        int right = (int)nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;   // record and keep searching left
                right  = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    int findLast(vector<int>& nums, int target) {
        int left   = 0;
        int right  = (int)nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;   // record and keep searching right
                left   = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};