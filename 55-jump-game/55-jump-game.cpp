class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int start = 0, reach = 0, maxReach = 0, len = nums.size() - 1;
        while(start < len) {
            int maxReach = INT_MIN;
            for( ; start <= reach; start++ ) {
                int tmp = start + nums[start];
                maxReach = max(maxReach, tmp);
                if (maxReach >= (len))
                    return true;
            }
            if (maxReach == reach)
                return false;
            reach = maxReach;
        };
        return true;
    }
};