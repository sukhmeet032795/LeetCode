class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int tmp = 0, prev = 0;
        for (auto &num : nums) {
            tmp = num;
            num += prev;
            prev = num;
        }
        return nums;
    }
};