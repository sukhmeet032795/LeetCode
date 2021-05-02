class Solution {
public:
    int jump(vector<int>& nums) {
        
        int len = nums.size();
        
        if(len == 1)
            return 0;
        
        int end = 0, i = 0, maxEnd = 0, steps = 0;
        
        for( ; i <= (len - 1); )
        {
            steps++;
            for( ; i <= end; i++)
            {
                int tmp = i + nums[i];
                maxEnd = max(maxEnd, tmp);
                
                if(maxEnd >= (len - 1))
                    return steps;
            }
            
            if(end == maxEnd)
                return 0;
            end = maxEnd;
        };
        
        return 0;
    }
};