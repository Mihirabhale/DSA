class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> result;
        bool arr[101]={false};
        for(int x : bulbs){
            arr[x]=!arr[x];
        }

        for(int i=0; i<=100; i++){
            if(arr[i]) result.push_back(i);
        }
        return result;
    }
};