class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int Min = INT_MAX, Max = INT_MIN, len = nums.size();
        
        bool check = false;
        for(int i = 0; i < (len - 1); i++)
        {
            if(nums[i] > nums[i+1])
                check = true;
            
            if(check)
                Min = min(Min, nums[i+1]);
        };
        
        check = false;
        for(int i = (len - 1); i > 0; i--)
        {
            if(nums[i] < nums[i-1])
                check = true;
            
            if(check)
                Max = max(Max, nums[i-1]);
        };
        
        // cout<<Min<<" "<<Max<<endl;
        
        if(Min == INT_MAX)
            return 0;
        
        int minInd = 0, maxInd = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] > Min)
            {
                minInd = i;
                break;
            }
        };
        
        for(int i = (len - 1); i >= 0; i--)
        {
            if(nums[i] < Max)
            {
                maxInd = i;
                break;
            }
        };
        
        // cout<<minInd<<" "<<maxInd<<endl;
        
        return (maxInd - minInd + 1);
    }
};