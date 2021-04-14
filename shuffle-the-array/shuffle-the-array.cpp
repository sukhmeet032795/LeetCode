class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> output(n*2);
        int start = 0, end = n, len = nums.size();
        
        int ind = 0;
        while(start < n && end < len)
        {
            output[ind++] = nums[start++];
            output[ind++] = nums[end++];
        }
        
        return output;
    }
};