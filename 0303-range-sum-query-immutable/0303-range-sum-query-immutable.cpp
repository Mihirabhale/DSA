class NumArray {
public:
    vector<int> prefixSum;

    NumArray(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            prefixSum.push_back(count);
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left - 1];
    }
};