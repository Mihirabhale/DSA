class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        sort(nums.begin(), nums.end());
        set<vector<int>> resultSet;  // handles duplicates automatically

        for (int i = 0; i < (int)nums.size() - 2; i++) {
            int left  = i + 1;
            int right = (int)nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    resultSet.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        // convert set to vector
        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};