class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = (int)nums.size();
        int i = 0;

        while (i < n) {
            int start = nums[i];

            // extend range as long as consecutive
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            if (nums[i] == start) {
                // single number
                result.push_back(to_string(start));
            } else {
                // range
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            }

            i++;
        }

        return result;
    }
};