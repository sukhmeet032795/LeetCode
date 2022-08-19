class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int lastSmallerInd = INT_MIN;
        
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i])
                lastSmallerInd = i-1;
        };
        
        if (lastSmallerInd == INT_MIN) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int firstBigger = INT_MIN;
        for(int i = (nums.size() - 1); i > lastSmallerInd; i--) {
            if (nums[i] > nums[lastSmallerInd]) {
                firstBigger = i;
                break;
            }
        }
        
        swap(nums[lastSmallerInd], nums[firstBigger]);
        sort(nums.begin() + lastSmallerInd + 1, nums.end());
    }
};