class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int len = nums.size();
        long ans = INT_MIN;
        
        for(int i = 0; i < (len-2); i++) {
            int j = (i + 1), k = (len - 1);
                        
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                };
                
                if (sum > target)
                    k--;
                else 
                    j++;
            };
        };
        
        return static_cast<int>(ans);
    }
};