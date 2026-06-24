class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int result = 0;
        sort(cost.begin(), cost.end(), greater<int>());  // sort descending directly

        for (int i = 0; i < (int)cost.size(); i++) {
            if (i % 3 != 2) {  // skip every 3rd item (index 2,5,8...)
                result += cost[i];
            }
        }

        return result;
    }
};