class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int len = nums.size(), med;
        
        if(len % 2 != 0)
            med = nums[len / 2];
        else
            med = ((nums[len / 2]) + (nums[(len / 2) - 1])) >> 1;
        
        int count = 0;
        for(int i = 0; i < len; i++)
            count += abs(med - nums[i]);
        
        return count;
    }
};