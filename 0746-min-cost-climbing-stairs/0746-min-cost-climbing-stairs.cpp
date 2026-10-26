class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int minCost[cost.size()];
        minCost[0]=cost[0];
        minCost[1]=cost[1];
        for(int i=2; i<cost.size();i++){
            minCost[i]=min(minCost[i-1],minCost[i-2])+cost[i];
        }
        return min(minCost[cost.size()-1],minCost[cost.size()-2]);
    }
};