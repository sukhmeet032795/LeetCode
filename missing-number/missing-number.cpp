class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int len = nums.size();
        int total = (len*(len+1)) >> 1;
        
        for(int i = 0; i < len; i++)
            total -= nums[i];
        
        return total;
    }
};