class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int len = nums.size();
        int end = 0, i = 0, maxEnd = 0;
        
        for( ; i <= (len-1); )
        {
            for( ; i <= end; i++)
            {
                int tmp = i + nums[i];
                maxEnd = max(maxEnd, tmp);
                
                if(maxEnd >= (len - 1))
                    return true;
            }
            
            if(end == maxEnd)
                break;
            end = maxEnd;
        }
        
        return false;
    }
};