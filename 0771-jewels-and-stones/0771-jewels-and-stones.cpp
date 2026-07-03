class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;

        for (char c : stones) {
            if (jewels.find(c) != string::npos) {
                count++;
            }
        }

        return count;
    }
};