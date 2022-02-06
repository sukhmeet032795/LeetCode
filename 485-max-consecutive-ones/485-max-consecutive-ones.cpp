class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int len = nums.size(), count = 0, Max = 0;
        for(int i = 0; i < len; i++) {
            if(nums[i] != 1) {
                Max = max(Max, count);
                count = 0;
            }
            else
                count++;
        }
        Max = max(Max, count);
        
        return Max;
    }
};