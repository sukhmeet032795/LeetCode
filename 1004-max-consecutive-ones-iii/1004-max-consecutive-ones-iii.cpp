class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int len = nums.size();
        int nZeros = 0, nOnes = 0, Max = 0, ind = 0;
        
        for( ; ind < len && nZeros < k; ind++) {
            if(nums[ind] == 1)
                nOnes++;
            else
                nZeros++;
        }
        
        Max = max(Max, nOnes + nZeros);
        int start = 0;
        
        while(ind < len) {
            
            if(nums[ind] == 1)
                nOnes++;
            else
                nZeros++;
                
            while(nZeros > k) {
                
                if(nums[start++] == 1)
                    nOnes--;
                else
                    nZeros--;
                
                Max = max(Max, nOnes + nZeros);
            }
            
            Max = max(Max, nOnes + nZeros);
            ind++;
        }
        
        return Max;
    }
};