class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> out(nums.size());
        k = k % nums.size();
        for(int i = 0; i < nums.size(); i++) {
            out[((k + i)%nums.size())] = nums[i];
        }
        nums = out;
    }
};