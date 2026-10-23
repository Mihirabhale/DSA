class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int count=0;
        for(int x : nums) count+=x;
        int left_sum=0;
        for(int i=0;i<nums.size();i++){
            int right_sum=count-left_sum-nums[i];
            if(left_sum==right_sum) return i;
            left_sum+=nums[i];
        }
        return -1;
    }
};