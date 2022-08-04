class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int tSum = 0, lSum = 0;
        tSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        for(int i = 0; i < nums.size(); i++) {
            tSum -= nums[i];
            if (tSum == lSum)
                return i;
            lSum += nums[i];
        };
        return -1;
    }
};