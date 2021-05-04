class Solution {
public:
    int rob(vector<int>& nums) {
        
        int len = nums.size();
        
        if(len == 1)
            return nums[0];
        
        int num1 = nums[0];
        int num2 = max(num1, nums[1]);
        
        for(int i = 2; i < len; i++)
        {
            int tmp = max(num2, num1 + nums[i]);
            num1 = num2;
            num2 = max(tmp, num2);
        }
        
        return max(num1, num2);
    }
};