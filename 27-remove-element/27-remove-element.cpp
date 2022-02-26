class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int start = 0;
        for(int i = 0; i < len; i++) {
            if (nums[i] == val) {
                continue;
            }
            nums[start++] = nums[i];
        }
        
        return start;
    }
};