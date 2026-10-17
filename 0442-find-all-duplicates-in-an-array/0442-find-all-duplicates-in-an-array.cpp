class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int c : nums){
            count[c]++;
        }
        vector<int> result;
        for(auto& p : count){
            if(p.second==2){
                result.push_back(p.first);
            }
        }
        return result;
    }
};