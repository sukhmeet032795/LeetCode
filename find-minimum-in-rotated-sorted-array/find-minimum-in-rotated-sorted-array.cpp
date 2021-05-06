class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int len = nums.size();
        int start = 0, end = (len - 1);
        
        while(start < end)
        {
            int mid = start + ((end - start) >> 1);
            
            if(nums[mid] <= nums[end])
                end = mid;
            else
                start = mid+1;
        }
        
        return nums[start];
    }
};