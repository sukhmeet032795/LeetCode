class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size(), mid = 0;
        while(start < end) {
            mid = (start + end) >> 1;
            
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        };
        
        return start;
    }
};