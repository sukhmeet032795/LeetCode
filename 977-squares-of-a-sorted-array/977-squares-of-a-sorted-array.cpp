class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        auto sq = [&](vector<int>& nums) -> vector<int> {
            for(auto &num : nums) {
                num = num*num;
            }
            return nums;
        };
        
        nums = sq(nums);
        int start = 0, end = nums.size() - 1;
        sort(nums.begin(), nums.end());
        
        return nums;
    }
};

